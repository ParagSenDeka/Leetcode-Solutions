#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int n;
    int f(int i, int xorsum, vector<int> &nums)
    {
        if (i == n)
            return xorsum;
        int x = nums[i];
        int take = f(i + 1, xorsum ^ x, nums);
        int notake = f(i + 1, xorsum, nums);
        return take + notake;
    }
    int subsetXORSum(vector<int> &nums)
    {
        n = nums.size();
        return f(0, 0, nums);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3};
    cout << sol.subsetXORSum(nums);
}