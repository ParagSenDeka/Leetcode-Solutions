#include<iostream>
#include<algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) -> int
        {
            while (left > -1 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }
            return right - left - 1;
        };

        for (int i = 0; i < s.length(); i++)
        {
            // Try both odd and even length palindromes
            int len1 = expand(i, i);     // Odd length
            int len2 = expand(i, i + 1); // Even length

            int len = max(len1, len2);
            if (len > maxLen)
            {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main()
{
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}