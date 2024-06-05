#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> result;
        vector<int> min_freq(26, INT_MAX);
        for (auto &word : words)
        {
            vector<int> freq(26, 0);
            for (char c : word)
            {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i)
            {
                min_freq[i] = min(min_freq[i], freq[i]);
            }
        }

        for (int i = 0; i < 26; ++i)
        {
            while (min_freq[i]-- > 0)
            {
                result.push_back(string(1, i + 'a'));
            }
        }
        return result;
    }
};

int main()
{
    vector<string> word = {"helo", "bella", "ella"};
    Solution sol;
    vector<string> result = sol.commonChars(word);
    for (auto c : result)
    {
        cout << c;
    }
}