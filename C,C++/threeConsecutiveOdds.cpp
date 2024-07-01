#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0, found = 0;
        while (i < arr.size()) {
            arr[i] % 2 != 0 ? found++ : found = 0;
            i++;
            if (found == 3) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    vector<int>arr={1,2,3,5,7};
    Solution sol;
    cout<<sol.threeConsecutiveOdds(arr);
}