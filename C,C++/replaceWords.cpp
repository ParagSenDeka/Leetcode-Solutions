#include<iostream>
#include<vector>
#include<set>
#include<sstream>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        set<string> s(begin(dict), end(dict));
        istringstream iss(sentence);
        vector<string> temp;
        string word, res; 

        while(iss >> word) temp.push_back(word);
        for(string t : temp) {
            int i = 0;
            while(i++ <= t.length()) {
                string curr = t.substr(0, i);
                if(s.find(curr) != s.end()) {
                    res += curr + " ";
                    break;
                }
                
                if(i == t.length()) res += curr + " ";
            }
        }

        res.erase(res.size() - 1);
        return res;
    }
};

int main(){
    vector<string> dict={"cat","bat","rat"};
    string sentence="the cattle was rattled by the battery";
    Solution s;
    cout<<s.replaceWords(dict,sentence);
}