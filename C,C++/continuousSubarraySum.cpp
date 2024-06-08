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

int main(){
    vector<int>nums={23,2,6,4,7};
    int k=7;
    Solution sol;
    cout<<sol.checkSubarraySum(nums,k);
}