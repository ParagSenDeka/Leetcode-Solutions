#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> countMap;
        vector<int> remaining, result;
        // Initialize count map with relative order elements
        for (int i : arr2)
        {
            countMap[i];
        }
        // Count occurrences of elements in target array
        for (int i : arr1)
        {
            if (countMap.find(i) != countMap.end())
            {
                countMap[i]++;
            }
            else
            {
                remaining.push_back(i);
            }
        }
        // Sort the remaining elements
        sort(remaining.begin(), remaining.end());
        // Add elements as per relative order
        for (int i : arr2)
        {
            for (int j = 0; j < countMap[i]; j++)
            {
                result.push_back(i);
            }
        }
        // Add remaining elements
        for (int i : remaining)
        {
            result.push_back(i);
        }
        return result;
    }
};

int main()
{
    vector<int> arr1 = {3, 2, 3, 1, 4, 5, 6}, arr2 = {1, 2, 3};
    Solution sol;
    vector<int> result = sol.relativeSortArray(arr1, arr2);
    for (int i : result)
    {
        cout << i;
    }
}