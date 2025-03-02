#include "iostream"
#include "vector"
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1, 55};
    cout << sol.singleNumber(nums);
}