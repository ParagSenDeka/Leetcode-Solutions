#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> charCount;
        for (char c : s)
        {
            charCount[c]++;
        }

        int maxLength = 0;
        bool hasOdd = false;

        for (auto [char_, count] : charCount)
        {
            maxLength += (count / 2) * 2; 
            if (count % 2 == 1)
            {
                hasOdd = true; 
            }
        }

        if (hasOdd)
        {
            maxLength++;
        }

        return maxLength;
    }
};

int main()
{
    string s = "abccccdd";
    Solution sol;
    cout << sol.longestPalindrome(s);
}