#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string firstString = strs[0];
        string res = "";
        for (int i = 0; i < firstString.size(); i++)
        {
            bool isCommon = true;
            char currentChar = firstString[i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != currentChar)
                {
                    isCommon = false;
                    break;
                }
                if (isCommon)
                {
                    res += currentChar;
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    Solution sol;
    cout << sol.longestCommonPrefix(strs);
}