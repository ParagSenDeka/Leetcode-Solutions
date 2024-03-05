#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos = 0, neg = 1;
        for (int i : nums) {
            if (i > 0) {
                ans[pos] = i;
                pos += 2;
            }
            else {
                ans[neg] = i;
                neg += 2;
            }
        }
        return ans; 
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> result = solution.rearrangeArray(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
