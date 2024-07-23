#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>count(201,0);
        for(auto i:nums){
            count[i+100]++;
        }
        sort(nums.begin(),nums.end(),[count](int a,int b){
            if(count[a+100]==count[b+100]){return a>b;}
            return count[a+100]<count[b+100];
        });
        return nums;
    }
};

int main(){
    Solution sol;
    vector<int>nums={2,2,2,3,1,1};
    auto result=sol.frequencySort(nums);
    for(int i:result){
        cout<<i<<endl;
    }
}