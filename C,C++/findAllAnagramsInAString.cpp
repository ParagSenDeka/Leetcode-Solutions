#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        map<int, int> mp1, mp2;

        for (auto x : p)
        {
            mp1[x]++;
        }

        int i = 0;
        int j = p.size();
        int pointer = i;

        while (pointer < j)
        {
            mp2[s[pointer]]++;
            pointer++;
        }

        while (j < s.size())
        {
            if (mp1 == mp2)
            {
                ans.push_back(i);
            }
            mp2[s[i]]--;
            mp2[s[j]]++;

            if (mp2[s[i]] == 0)
            {
                mp2.erase(s[i]);
            }
            i++;
            j++;
        }
        if (mp1 == mp2)
        {
            ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution sol;
    auto result = sol.findAnagrams(s, p);
    for (auto i : result)
    {
        cout << i << " ";
    }
}