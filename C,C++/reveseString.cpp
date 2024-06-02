#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
    }

    void reverse(vector<char>& s,int left,int right){
        if(left>=right)return;
        swap(s[left],s[right]);
        reverse(s,left+1,right-1);
    }
};

int main(){
    vector<char> string={'h','e','l','l','o'};
    Solution sol;
    sol.reverseString(string);
    for(int i=0;i<string.size();i++){
        cout<<string[i];
    }
}