#include<iostream>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.size();i++){
            ans+=abs(s[i]-s[i-1]);
        }
        return ans;
    }
};

int main(){
    string s="zaz";
    Solution solution;
    cout<<solution.scoreOfString(s);
}