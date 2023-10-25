#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

TreeNode* buildExpressionTree(string expression) {
    TreeNode* root = nullptr;
    TreeNode* current = nullptr;
    TreeNode* newOperand = nullptr;

    for (char c : expression) {
        if (!isOperator(c)) {
            newOperand = new TreeNode(c);

            if (!root) {
                root = newOperand;
            } else if (current->right == nullptr) {
                current->right = newOperand;
            } else if (current->left == nullptr) {
                current->left = newOperand;
            }
        } else if (isOperator(c)) {
            if (root && !current) {
                current = root;
            }
            TreeNode* newOperator = new TreeNode(c);
            newOperator->left = current->right;
            current->right = newOperator;
            current = newOperator;
        }
    }
    return root;
}

void postOrder(TreeNode* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    string expression = "3*(4+2)+5";
    TreeNode* expressionTree = buildExpressionTree(expression);

    cout << "Post-order traversal of the expression tree: ";
    postOrder(expressionTree);

    return 0;
}
