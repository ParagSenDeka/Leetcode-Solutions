#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string firstString = strs[0];
        string res = "";

        for (int i = 0; i < firstString.size(); i++)
        {
            char currentChar = firstString[i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != currentChar)
                {
                    return res;
                }
            }
            res += currentChar;
        }
        return res;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs2 = {"car", "cir"};
    Solution sol;
    cout << sol.longestCommonPrefix(strs);
    cout << endl;
    cout << sol.longestCommonPrefix(strs2);
}