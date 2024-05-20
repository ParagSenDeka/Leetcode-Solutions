#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (root->left == nullptr && root->right == nullptr && root->val == target)
        {
            return nullptr;
        }
        return root;
    }
};

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main()
{
    // Create a sample tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    // Print the original tree
    cout << "Original tree (in-order): ";
    printTree(root);
    cout << endl;

    // Remove leaf nodes with the target value
    int target = 2;
    Solution solution;
    root = solution.removeLeafNodes(root, target);

    // Print the modified tree
    cout << "Modified tree (in-order): ";
    printTree(root);
    cout << endl;

    return 0;
}