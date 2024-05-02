#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        int answer = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 &&
                std::binary_search(nums.begin(), nums.end(), -1 * nums[i])) {
                if (nums[i] > answer) {
                    answer = nums[i];
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<int>nums={-1,10,6,7,-7,1};
    std::cout<<solution.findMaxK(nums);
}