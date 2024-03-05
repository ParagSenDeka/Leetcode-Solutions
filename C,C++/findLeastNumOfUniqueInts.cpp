#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> arr, int k) {
        unordered_map<int,int>freq;
        for(auto i:arr){
            freq[i]++;
        }
        vector<pair<int,int>>store;
        for(auto x:freq){
            store.push_back({x.second,x.first});
        }
        sort(store.rbegin(),store.rend());

        while(k>0){
            int required=min(k,store.back().first);
            k-=required;
            store.back().first-=required;

            if(!store.back().first){
                store.pop_back();
            }
        }
        return store.size();
    }
};

int main(){
    vector<int> nums = {4,3,1,1};
    int k=2;
    Solution solution;
    cout << "Least Number of Unique digits: "<<solution.findLeastNumOfUniqueInts(nums,k);
    return 0;
}
