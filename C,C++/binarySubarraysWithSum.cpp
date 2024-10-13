#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSums;
        int sum = 0;
        int result = 0;
        
        prefixSums[0] = 1;
        
        for (int num : nums) {
            sum += num;
            if (prefixSums.find(sum - goal) != prefixSums.end()) {
                result += prefixSums[sum - goal];
            }
            prefixSums[sum]++;
        }
        
        return result;
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,0,1,0,1};
    int goal=3;
    cout<<sol.numSubarraysWithSum(nums,goal);
}