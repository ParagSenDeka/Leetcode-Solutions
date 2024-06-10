#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int result = 0;
        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());
        for (int i = 0; i < heights.size(); i++)
        {
            if (sortedHeights[i] != heights[i])
            {
                result++;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> heights = {1, 1, 4, 2, 1, 2};
    Solution sol;
    cout << sol.heightChecker(heights);
}