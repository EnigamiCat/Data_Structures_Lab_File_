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


TreeNode* constructBST(vector<int>& preorder, int& index, int minValue, int maxValue) {
    if (index >= preorder.size()) {
        return nullptr;
    }

    int value = preorder[index];
    if (value < minValue || value > maxValue) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(value);
    index++;

   
    root->left = constructBST(preorder, index, minValue, value);
    root->right = constructBST(preorder, index, value, maxValue);

    return root;
}


void preorderToPostorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    preorderToPostorder(root->left);
    preorderToPostorder(root->right);


    cout << root->data << " ";
}

int main() {
    vector<int> preorder = {8, 3, 1, 6, 4, 7, 10, 14};

    int index = 0;
    TreeNode* root = constructBST(preorder, index, INT_MIN, INT_MAX);

    cout << "Postorder traversal of the tree: ";
    preorderToPostorder(root);

    return 0;
}
