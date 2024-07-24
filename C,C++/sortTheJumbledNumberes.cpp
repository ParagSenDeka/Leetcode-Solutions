#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto translate_integer = [mapping](int num) -> int {
            string digits = to_string(num);
            for (char digit : digits) {
                digit = '0' + mapping[digit - '0'];
            }
            return stoi(digits);
        };

        unordered_map<int, int> number_mapping;
        for (int num : nums) {
            if (number_mapping.find(num) == number_mapping.end()) {
                number_mapping[num] = translate_integer(num);
            }
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return number_mapping[a] < number_mapping[b];
        });

        return nums;
    }
};

int main(){
    vector<int> mapping={8,9,4,0,2,1,3,5,7,6};
    vector<int> nums={991,338,38};
    Solution sol;
    auto result=sol.sortJumbled(mapping,nums);
    for(auto i:result){
        cout<<i<<endl;
    }
}