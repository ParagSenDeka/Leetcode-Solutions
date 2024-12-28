#include "iostream"
#include "vector"
#include "queue"
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
    void dfs(TreeNode *node, int level, vector<double> &sum, vector<int> &count)
    {
        if (!node)
            return;
        if (level == sum.size())
        {
            sum.push_back(node->val);
            count.push_back(1);
        }
        else
        {
            sum[level] += node->val;
            count[level]++;
        }
        dfs(node->left, level + 1, sum, count);
        dfs(node->right, level + 1, sum, count);
    }

    vector<double> averageOfLevels(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> count;
        vector<double> sum;
        dfs(root, 0, sum, count);

        vector<double> avg;
        for (int i = 0; i < sum.size(); i++)
        {
            avg.push_back(sum[i] / count[i]);
        }
        return avg;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<double> ans = s.averageOfLevels(root);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}