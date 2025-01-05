#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<size;i++){
            if(mp.find(nums[i])!=mp.end() && abs(i-mp[nums[i]])<=k){
                return true;
        }
        mp[nums[i]]=i;
    }
    return false;
    }
};

int main(){
    Solution s;
    vector<int>nums={1,1,3,1,2,3};
    int k=2;
    cout<<s.containsNearbyDuplicate(nums,k);
    return 0;
}