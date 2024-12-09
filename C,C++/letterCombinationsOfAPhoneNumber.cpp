#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    void solve(string digits, string output, int i, vector<string> &ans,
               string mapping[])
    {
        if (i >= digits.size())
        {
            ans.push_back(output);
            return;
        }
        int num = digits[i] - '0';
        string value = mapping[num];
        for (int j = 0; j < value.size(); j++)
        {
            output.push_back(value[j]);
            solve(digits, output, i + 1, ans, mapping);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        string mapping[10] = {"", "", "abc", "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string output;
        int i = 0;
        solve(digits, output, i, ans, mapping);
        return ans;
    }
};

int main(){
    Solution sol;
    auto res=sol.letterCombinations("23");
    for(auto i:res){
        cout<<i<<endl;
    }
}