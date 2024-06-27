#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* balanceBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};

// Utility function to print inorder traversal of a binary tree
void printInOrder(TreeNode* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
}

int main() {
    // Example input root = [1,null,2,null,3,null,4,null,null]
    vector<int> values = {1, INT_MAX, 2, INT_MAX, 3, INT_MAX, 4};
    vector<int> nodes;

    // Create a vector of nodes based on the input format
    for (int val : values) {
        if (val != INT_MAX) {
            nodes.push_back(val);
        }
    }

    // Balance the BST
    Solution solution;
    TreeNode* balancedRoot = solution.balanceBST(nodes);

    // Print inorder traversal of the balanced BST
    cout << "Inorder traversal of balanced BST: ";
    printInOrder(balancedRoot);
    cout << endl;

    return 0;
}
