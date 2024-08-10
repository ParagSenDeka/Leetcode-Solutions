#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& x : details) {
            int age = stoi(x.substr(11, 2));
            ans+=age>60;
        }
        return ans;
    }
};

int main(){
    vector<string>details={"7868190130M7522","5303914400F9211","9273338290F4010"};
    Solution sol;
    cout<<sol.countSeniors(details);
}