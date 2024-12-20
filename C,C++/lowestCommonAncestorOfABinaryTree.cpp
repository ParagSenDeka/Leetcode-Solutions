#include "iostream"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);

        if (leftLCA != nullptr && rightLCA != nullptr)
        {
            return root;
        }
        return leftLCA != nullptr ? leftLCA : rightLCA;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(7);

    Solution sol;
    auto ans = sol.lowestCommonAncestor(root, root->left, root->right);
    cout << ans->val;
}