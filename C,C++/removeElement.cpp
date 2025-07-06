#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0,size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int newSize = sol.removeElement(nums, val);
    
    cout << "New size: " << newSize << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}