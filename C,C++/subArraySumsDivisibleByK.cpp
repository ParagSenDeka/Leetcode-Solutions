#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0;
        int sum = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Empty subarray with sum 0

        for (int num : nums) {
            sum += num;
            int remainder = sum % k;

            // Handle negative remainders (ensure they're non-negative for map key)
            if (remainder < 0) {
                remainder += k;
            }

            if (prefixSumCount.count(remainder)) {
                result += prefixSumCount[remainder];
            }

            prefixSumCount[remainder]++; // Increment count for current prefix sum remainder
        }

        return result;
    }
};

int main(){
    vector<int>nums={4,5,0,-2,-3,1};
    int k=5;
    Solution sol;
    cout<<sol.subarraysDivByK(nums,k);
}