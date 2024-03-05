#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        
        int max_index = 0;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_index]){
                max_index = i;
                }
        }
        
        vector<int> result;
        while (max_index != -1) {
            result.push_back(nums[max_index]);
            max_index = prev[max_index];
            cout<<max_index<<endl;
        }
        
        return result;
    }
};

int main() {
    vector<int> nums = {10,5,10,20,40,60};
    Solution solution;
    vector<int> longestDivisibleSubset = solution.largestDivisibleSubset(nums);
    
    cout << "Longest Divisible Subset: ";
    for (int num : longestDivisibleSubset) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
