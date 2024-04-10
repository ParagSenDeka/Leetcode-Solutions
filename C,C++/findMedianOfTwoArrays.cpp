#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sortedArray(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),sortedArray.begin());
        sort(sortedArray.begin(),sortedArray.end());
        auto number=sortedArray.size();
        if(number%2!=0){
            return sortedArray[number/2];
        }
        else{
            return (static_cast<double>(sortedArray[number/2-1])+static_cast<double>(sortedArray[number/2]))/2.0;
        }
    }
};

int main(){
    vector<int>nums1={1,2,3,4};
    vector<int>nums2={5,6,7,8};
    Solution solution;
    cout<<solution.findMedianSortedArrays(nums1,nums2);
}