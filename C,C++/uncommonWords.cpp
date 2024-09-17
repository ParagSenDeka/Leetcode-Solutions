#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
#include <sstream>
using namespace std;


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>result;
        unordered_map<string, int> wordCount;

        string combined = s1 + " " + s2;

        istringstream iss(combined);
        string word;
        while (iss >> word) {
            wordCount[word]++;
        }

        for (auto it = wordCount.begin(); it != wordCount.end(); ++it) {
            if (it->second == 1) {
                result.push_back(it->first);
            }
        }
        if(result.empty()){
                result.push_back("SAME SENTENCES");
        }

        return result;
    }
};

int main(){
    Solution sol;
    string s1="this apple is sweet";
    string s2="this apple is sweet";
    auto result=sol.uncommonFromSentences(s1,s2);
    for(auto i:result){
        cout<<i<<endl;
    }
    return 0;
}
