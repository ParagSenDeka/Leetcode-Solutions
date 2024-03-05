#include <string>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int end = s.length();
        string longest;
        for (int i = 0; i < end; ++i) {
            for (int j = end; j > i; --j) {
                if (s[i] == s[j - 1]) {
                    // Check if the substring from i to j is a palindrome
                    if (isPalindrome(s, i, j)) {
                        string current = s.substr(i, j - i);
                        if (current.length() > longest.length()) {
                            longest = current;
                        }
                    }
                }
            }
        }

        return longest;
    }

private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end - 1]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};

#include <iostream>

int main() {
    Solution solution;

    // Test cases
    string input1 = "badaba";


    cout << "Longest Palindrome for \"" << input1 << "\": " << solution.longestPalindrome(input1) << endl;
    return 0;
}
