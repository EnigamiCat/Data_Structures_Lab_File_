#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void rightView(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

      
            if (i == levelSize - 1) {
                cout << current->data << " ";
            }

            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
}

int main() {
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Right View of the Binary Tree: ";
    rightView(root);

   
    return 0;
}
