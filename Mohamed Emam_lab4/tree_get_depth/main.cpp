#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

int getDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Depth of the tree: " << getDepth(root) << endl;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
