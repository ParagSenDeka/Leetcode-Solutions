#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int start=0;start<nums.size()-1;start++){
            for(int end=start;end<nums.size();end++){
                int subarraySum=0;
                for(int i=start;i<=end;i++){
                    subarraySum+=nums[i];
                }
                if(subarraySum==0 && k==0){
                    return true;
                }
                if(k!=0 && subarraySum%k==0){
                    return true;
                }
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int, int> remainderMap;
//         int cumulativeSum = 0;
        
//         // Step 1: Initialize Remainder Map
//         remainderMap[0] = -1;
        
//         // Step 2: Iterate Through the List
//         for (int i = 0; i < n; i++) {
//             // Step 3: Calculate Cumulative Sum
//             cumulativeSum += nums[i];
            
//             // Step 4: Calculate Remainder
//             int remainder = k == 0 ? cumulativeSum : cumulativeSum % k;
            
//             // Step 5: Update Remainder Map
//             if (remainderMap.count(remainder)) {
//                 // Check if segment length is at least two
//                 if (i - remainderMap[remainder] > 1) {
//                     return true;
//                 }
//             } else {
//                 remainderMap[remainder] = i;
//             }
//         }
        
//         // Step 6: Return the Result
//         return false;
//     }
// };

int main(){
    vector<int>nums={23,2,6,4,7};
    int k=7;
    Solution sol;
    cout<<sol.checkSubarraySum(nums,k);
}