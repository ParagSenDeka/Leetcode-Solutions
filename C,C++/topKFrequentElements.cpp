#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        vector<int>ans;
        for(auto num:nums){
            map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto entry:map){
            pq.push({entry.second, entry.first});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};

int main(){
    Solution sol;
    vector<int> nums={1,1,1,2,3,3};
    int k=2;
    auto ans= sol.topKFrequent(nums,k);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}