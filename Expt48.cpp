#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* findLCA(TreeNode* root, int node1, int node2) {
    if (root == nullptr) return nullptr;

    if (root->data == node1 || root->data == node2) {
         
        return root;
    }

    TreeNode* leftLCA = findLCA(root->left, node1, node2);
    TreeNode* rightLCA = findLCA(root->right, node1, node2);

    if (leftLCA && rightLCA) {
         
        return root;
    }

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
     
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int node1 = 4;
    int node2 = 5;

    TreeNode* lca = findLCA(root, node1, node2);

    if (lca) {
        cout << "Lowest Common Ancestor of " << node1 << " and " << node2 << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

 
    return 0;
}
