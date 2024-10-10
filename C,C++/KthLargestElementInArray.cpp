#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int result=0;
        priority_queue<int,vector<int>,greater<int>>min_heap(nums.begin(),nums.begin()+k);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>min_heap.top()){
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        return min_heap.top();
    }
};

int main(){
    Solution sol;
    vector<int>nums={3,2,1,5,6,4};
    int k=2;
    cout<<sol.findKthLargest(nums,k);
}