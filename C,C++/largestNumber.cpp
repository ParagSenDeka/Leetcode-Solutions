#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result= "";
        sort(nums.begin(),nums.end(),[=](int a,int b){
            return (to_string(a)+to_string(b))>(to_string(b)+to_string(a));
    });
        for(auto num:nums){
            result+=to_string(num);
        }
        if(result[0]=='0'){
            return "0";
        }
        else{
            return result;
        }
    }
};

int main(){
    vector<int>nums={10,2};
    Solution sol;
    cout<<sol.largestNumber(nums);
}