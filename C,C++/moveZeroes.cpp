#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[start], nums[i]);
                start++;
            }
        }
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution sol;
    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        if(i==nums.size()-1){
            cout << nums[i];
            break;
        }
        cout << nums[i] << ",";
    }
    return 0;
}