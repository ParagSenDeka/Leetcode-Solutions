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

        for (int i = 0; i < firstString.size(); ++i)
        {
            char c = firstString[i];
            bool isCommon = true;

            for (int j = 1; j < strs.size(); ++j)
            {
                if (i >= strs[j].size() || strs[j][i] != c)
                {
                    isCommon = false;
                    break;
                }
            }

            if (isCommon)
            {
                res += c;
            }
            else
            {
                break;
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