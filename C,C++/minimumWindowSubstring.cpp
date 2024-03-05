#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string ans = "";
        int i = 0, j = 0;
        int mini = INT_MAX; // checking min size
        unordered_map<char, int> mp;
        for (char c : t)
        {
            mp[c]++; // A B C
        }
        int count = mp.size(); // 3
        int start = 0;
        while (j < s.length())
        {
            char c = s[j];
            if (mp.find(c) != mp.end())
            {
                mp[c]--; // dec the freq
                if (mp[c] == 0)
                {
                    count--; // dec the cnt
                }
                cout<<"j:"<<j<<endl;
            }
            j++;
            while (count == 0)
            {
                cout<<"j:"<<j<<endl;
                cout<<"i:"<<i<<endl;
                if (mini > j - i)
                {
                    mini = j - i;
                    start = i;
                    cout<<mini<<endl<<start;
                }
                char c1 = s[i];
                if (mp.find(c1) != mp.end())
                {
                    mp[c1]++;
                    if (mp[c1] > 0)
                        count++;
                }
                i++; 
            }
        }
        if (mini != INT_MAX)
        {
            ans = s.substr(start, mini); // mini will have the min length
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "abd";
    string t = "ad";
    cout << solution.minWindow(s, t);
}