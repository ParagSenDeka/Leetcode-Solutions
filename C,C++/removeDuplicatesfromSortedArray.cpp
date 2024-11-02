#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i, j = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main(){
    Solution sol;
    vector<int>nums={0,0,1,1,1,2,2,3,3,4};
    cout<<sol.removeDuplicates(nums);
}