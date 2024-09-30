#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int i = 0, j = height.size() - 1;
        while(i<j){
            int currentArea=min(height[i],height[j])*(j-i);
            maxArea=max(currentArea,maxArea);

            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
};

int main(){
    vector<int>height={1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout<<sol.maxArea(height);
}