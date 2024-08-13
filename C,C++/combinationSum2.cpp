#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        findCombination(0,target,candidates,result,ds);
        return result;
    }

    void findCombination(int index,int target,vector<int>&arr,vector<vector<int>>&result,vector<int>&ds){
        if(target==0){
            result.push_back(ds);
            return;
        }
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            findCombination(i+1,target-arr[i],arr,result,ds);
            ds.pop_back();
        }
    }
};

int main(){
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    Solution sol;
    auto result=sol.combinationSum2(candidates,target);
    for(auto i:result){
        for(auto j:i){
            cout<<j;
        }
        cout<<endl;
    }
}