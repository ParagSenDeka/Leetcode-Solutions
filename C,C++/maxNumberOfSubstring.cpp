#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_map<char, int> map;
        int start = 0;

        for (int end = 0; end < s.size(); end++) {
            if (map.find(s[end]) != map.end()) {
                start = max(start, map[s[end]] + 1);
            }
            map[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main(){
    string s="pop";
    Solution solution;
    cout<<solution.lengthOfLongestSubstring(s);
}