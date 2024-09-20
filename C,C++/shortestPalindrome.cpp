#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int j=0;
        int n=s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == s[j]) {
                j++;
            }
        }

        if(j==n){
            return s;
        }

        string suffix=s.substr(j);
        cout<<suffix<<endl<<shortestPalindrome(s.substr(0,j))<<endl<<s.substr(j)<<endl;
        reverse(suffix.begin(),suffix.end());
        return suffix+shortestPalindrome(s.substr(0,j))+s.substr(j);
    }
};

int main(){
    string s="abcda";
    Solution sol;
    cout<<sol.shortestPalindrome(s);
}