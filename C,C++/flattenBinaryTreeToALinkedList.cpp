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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            v.push_back(root->val);
            preorder(root->left, v);
            preorder(root->right, v);
        }
    }

    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        vector<int> v;
        preorder(root, v);

        int n = v.size();
        TreeNode *curr = root;
        curr->left = NULL;

        for (int i = 1; i < n; i++)
        {
            TreeNode *temp = new TreeNode(v[i]);
            curr->right = temp;
            curr = temp;
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1,
                                  new TreeNode(2,
                                               new TreeNode(3),
                                               new TreeNode(4)),
                                  new TreeNode(5,
                                               nullptr,
                                               new TreeNode(6)));

    sol.flatten(root);
    TreeNode *curr = root;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->right;
    }
}
