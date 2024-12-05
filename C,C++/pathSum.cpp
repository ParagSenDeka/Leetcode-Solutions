#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    bool checkSum(TreeNode *root, int targetSum, int sum)
    {
        sum += root->val;
        if (sum == targetSum)
        {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr && sum != targetSum)
        {
            return false;
        }
        bool leftCheck = false, rightCheck = false;
        if (root->left != nullptr)
        {
            leftCheck = checkSum(root->left, targetSum, sum);
        }
        if (root->right != nullptr)
        {
            rightCheck = checkSum(root->right, targetSum, sum);
        }
        return leftCheck || rightCheck;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        return checkSum(root, targetSum, 0);
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(5, new TreeNode(4,new TreeNode(11,new TreeNode(7),new TreeNode(2)),nullptr),new TreeNode(8,new TreeNode(13),new TreeNode(4,nullptr,new TreeNode(1))));
    cout << sol.hasPathSum(root, 22);
}