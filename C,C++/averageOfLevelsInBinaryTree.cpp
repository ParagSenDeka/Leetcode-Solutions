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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(sum / size);
        }
        return ans;
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