#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int index = 0;
        int size = nums.size();
        if (nums.size() == 2) {
            return nums;
        };
        for (int i = 0; i < size; i++) {
            bool found = false;
            for (int j = 0; j < size; j++) {
                if (i != j && nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[index++] = nums[i];
                if (index == 2)
                    break;
            }
        }
        return result;
    }
};
int main(){
    vector<int>nums={1,2,1,2,4,5};
    Solution s;
    vector<int>solution=s.singleNumber(nums);
    for(int i=0;i<solution.size();i++){
        cout<<solution[i];
    }
}