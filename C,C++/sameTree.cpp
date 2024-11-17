#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> q1, q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty())
        {
            TreeNode *node1 = q1.front();
            TreeNode *node2 = q2.front();
            q1.pop();
            q2.pop();
            if(node1->val!=node2->val){
                return false;
            }

            if (node1->left && node2->left){
                q1.push(node1->left);
                q2.push(node2->left);
            }
            else if(node1->left || node2->left){
                return false;
            }
            if (node1->right && node2->right){
                q1.push(node1->right);
                q2.push(node2->right);
            }
            else if(node1->right || node2->right)
            {
                return false;
            }
            
        }
        return q1.empty() && q2.empty();
    }
};

int main(){
    Solution sol;
    TreeNode* p1=new TreeNode(1);
    TreeNode* p2=new TreeNode(2);
    TreeNode* p3=new TreeNode(3);
    p1->left=p2;
    p1->right=p3;
    TreeNode* q1=new TreeNode(1);
    TreeNode* q2=new TreeNode(2);
    TreeNode* q3=new TreeNode(3);
    q1->left=q2;
    q1->right=q3;
    cout<<sol.isSameTree(p1,q1);
}