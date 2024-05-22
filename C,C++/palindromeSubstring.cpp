#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
    void backtrack(const string &s, int start, vector<string> &path,
                   vector<vector<string>> &result)
    {
        if (start == s.size())
        {
            result.push_back(path);
            return;
        }
        for (int end = start + 1; end <= s.size(); ++end)
        {
            if (isPalindrome(s, start, end - 1))
            {
                cout << s.substr(start, end - start) << endl;
                path.push_back(s.substr(start, end - start));
                backtrack(s, end, path, result);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left > right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> result = sol.partition("aab");
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Col" << i << ":" << endl;
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << endl;
        }
    }
}