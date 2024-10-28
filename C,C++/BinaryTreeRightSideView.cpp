#include <iostream>
#include <vector>
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
    vector<int> ans;
    int ma = 0;

    void traverse(TreeNode *root, int curr)
    {
        if (root == NULL)
            return;

        if (curr > ma)
        {
            ma++;
            ans.push_back(root->val);
        }

        traverse(root->right, curr +1);
        traverse(root->left, curr +1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        traverse(root, 1);
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    auto result = sol.rightSideView(root);
    for (auto i : result)
    {
        cout << i << " ";
    }
}