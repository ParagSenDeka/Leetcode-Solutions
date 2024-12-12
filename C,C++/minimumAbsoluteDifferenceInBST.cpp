#include "iostream"
#include "algorithm"
#include "limits.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int minimum = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root, prev, minimum);
        return minimum;
    }

    void inorder(TreeNode* node, TreeNode*& prev, int& minimum) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, prev, minimum);
        if (prev != nullptr) {
            minimum = min(minimum, node->val - prev->val);
        }
        prev = node;
        inorder(node->right, prev, minimum);
    }
};

int main(){
  Solution sol;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << sol.getMinimumDifference(root) << endl;
}