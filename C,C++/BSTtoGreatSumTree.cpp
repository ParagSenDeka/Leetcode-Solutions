#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum = 0;
    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->right);
            sum += root->val;
            root->val = sum;
            traverse(root->left);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};

// Helper function to print the tree in-order for verification
void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    // Creating the binary search tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    // Transform the BST to GST
    Solution solution;
    solution.bstToGst(root);

    // Print the transformed tree (GST) in-order
    cout << "In-order traversal of the Greater Sum Tree:" << endl;
    printInOrder(root);
    cout << endl;

    return 0;
}
