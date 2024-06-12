#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size=nums.size();
        int zeroes=0,ones=0;
        for(int num:nums){
            if(num==0){
                zeroes++;
            }
            if(num==1){
                ones++;
            }
        }
        for(int i=0;i<zeroes;i++){
            nums[i]=0;
        }
        for(int i=zeroes;i<zeroes+ones;i++){
            nums[i]=1;
        }
        for(int i=zeroes+ones;i<size;i++){
            nums[i]=2;
        }
    }
};

int main(){
    Solution sol;
    vector<int>nums={2,1,2,0,0,1};
    cout<<"Before sorting : ";
    for(int num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
    sol.sortColors(nums);
    cout<<"After sorting : ";
    for(int num:nums){
        cout<<num<<" ";
    }
}