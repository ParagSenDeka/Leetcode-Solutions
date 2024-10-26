#include <iostream>
// #include <climits>
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
private:
    int maxGain(TreeNode *node, int &maxSum)
    {
        if (node == nullptr)
            return 0;

        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        int currentSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentSum);

        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<sol.maxPathSum(root);
}