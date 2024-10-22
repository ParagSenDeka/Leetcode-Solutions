#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=-1;
        for(auto num:nums){
            if(count==0){
                candidate=num;
            }
            count+=(candidate==num)?1:-1;
        }
        count=0;
        for(int num:nums){
            if(num==candidate){
                count++;
            }
        }
        if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1;
    }
    }
};

int main(){
    vector<int>nums={2,2,1,1,1,2,2};
    Solution sol;
    cout<<sol.majorityElement(nums);
}