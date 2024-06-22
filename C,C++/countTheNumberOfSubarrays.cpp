#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>countMap;
        countMap[0]=1;
        int crrSum=0,result=0;

        for(int num:nums){
            crrSum+=(num%2);
            if(countMap.find(crrSum-k)!=countMap.end()){
                result+=countMap[crrSum-k];
            }
            countMap[crrSum]++;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int>nums={2,1,4,1};
    int k=2;
    cout<<sol.numberOfSubarrays(nums,k);
}