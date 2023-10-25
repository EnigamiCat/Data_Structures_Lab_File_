#include <iostream>
#include <vector>
#include<climits>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


TreeNode* constructBST(vector<int>& postorder, int& index, int minValue, int maxValue) {
    if (index < 0) {
        return nullptr;
    }

    int value = postorder[index];
    if (value < minValue || value > maxValue) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(value);
    index--;

   
    root->right = constructBST(postorder, index, value, maxValue);
    root->left = constructBST(postorder, index, minValue, value);

    return root;
}


void postorderToPreorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    
    cout << root->data << " ";

    
    postorderToPreorder(root->left);
    postorderToPreorder(root->right);
}

int main() {
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    int index = postorder.size() - 1;
    TreeNode* root = constructBST(postorder, index, INT_MIN, INT_MAX);

    cout << "Preorder traversal of the tree: ";
    postorderToPreorder(root);

    return 0;
}
