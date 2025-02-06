#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int curSize = q.size();
            vector<int> level(curSize);
            for (int i = 0; i < curSize; i++)
            {
                auto cur = q.front();
                q.pop();
                int index = leftToRight ? i : curSize - 1 - i;
                level[index] = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            leftToRight = !leftToRight;
            res.push_back(level);
        }
        return res;
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    auto nums = sol.zigzagLevelOrder(root);
    for(auto num:nums){
        cout << "[ ";
        for(auto i:num){
            cout << i << " ";
        }
        cout << "]";
    }
}