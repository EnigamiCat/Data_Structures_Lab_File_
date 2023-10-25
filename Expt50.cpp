#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void bottomView(TreeNode* root) {
    if (!root) return;

    map<int, int> bottomViewMap;  
    queue<pair<TreeNode*, int>> q; 

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int distance = q.front().second;
        q.pop();

        bottomViewMap[distance] = current->data;  

        if (current->left) {
            q.push(make_pair(current->left, distance - 1));
        }
        if (current->right) {
            q.push(make_pair(current->right, distance + 1));
        }
    }

    for (const auto& entry : bottomViewMap) {
        cout << entry.second << " ";
    }
}

int main() {
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    cout << "Bottom View of the Binary Tree: ";
    bottomView(root);

   
    return 0;
}
