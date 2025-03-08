#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>
        >pair;
        for(int i=0;i<nums.size();i++){
            pair.push_back({nums[i],i});
        }
        sort(pair.begin(),pair.end());
        vector<int>ans;
        int j=nums.size()-1;
        for(int i=0;i<nums.size();){
            int sum=pair[i].first+pair[j].first;
            if(sum==target){
                ans.push_back(pair[i].second);
                ans.push_back(pair[j].second);
                break;
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj1;
    vector<int>nums={2,7,11,15};
    int target=9;
    vector<int>result=obj1.twoSum(nums,target);
    for(auto index:result){
        cout<<index;
    }
}