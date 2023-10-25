#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

 
TreeNode* findMinValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

 
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;  

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else { 
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
         
        TreeNode* temp = findMinValueNode(root->right);
        root->data = temp->data;  
        root->right = deleteNode(root->right, temp->data);  
    }
    return root;
}

 
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    int keyToDelete ;
    cout<<"Enter a key to delete : ";
    cin>>keyToDelete;

    cout << "In-order traversal before deletion: ";
    inOrderTraversal(root);
    cout << endl;

    root = deleteNode(root, keyToDelete);

    cout << "In-order traversal after deletion: ";
    inOrderTraversal(root);
    cout << endl;

  
    return 0;
}
