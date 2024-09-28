#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,int>m;
        string vowels="aAeEiIoOuU";
        for(char vowel:vowels){
            m[vowel]=2;
        }
        int i=0,j=s.length()-1;
        char temp;

        while(i<j){
            while(i<j && m[s[i]]!=2){
                i++;
            }
            while(i<j && m[s[j]]!=2){
                j--;
            }
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;

            i++;
            j--;
        }
        return s;
    }
};

int main(){
    string s="hello";
    Solution sol;
    cout<<sol.reverseVowels(s);
}