#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(const std::vector<int>& nums) {
    int max_val = *max_element(nums.begin(), nums.end());
    int longest = 0, current_length = 0;

    for (int num : nums) {
        if (num == max_val) {
            current_length++;
        } else {
            longest = std::max(longest, current_length);
            current_length = 0;
        }
    }

    longest = std::max(longest, current_length);

    return longest;
}
};

int main(){
    Solution sol;
    cout<<sol.longestSubarray({2,3,3,2,1});
}