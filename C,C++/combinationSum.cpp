#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;
        makeCombination(candidates, target, 0, combination, 0, result);
        return result;
    }

private:
    void makeCombination(vector<int> &candidates, int target, int index, vector<int> &combination, int sum, vector<vector<int>> &result)
    {
        if (sum == target)
        {
            result.push_back(combination);
            return;
        }
        if (sum > target || index >= candidates.size())
        {
            return;
        }

        combination.push_back(candidates[index]);
        makeCombination(candidates, target, index, combination, sum + candidates[index], result);
        combination.pop_back();
        makeCombination(candidates, target, index + 1, combination, sum, result);
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution sol;
    auto result = sol.combinationSum(candidates, target);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j;
        }
        cout << " ";
    }
}