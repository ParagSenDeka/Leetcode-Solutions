#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0, k = minutes;
        if (k >= n) {
            for (int i = 0; i < n; i++) {
                sum += customers[i];
            }
            return sum;
        }
        int temp = 0;
        for (int i = 0; i < k; i++) {
            if (grumpy[i] == 1) {
                temp += customers[i];
            }
        }

        int maxi = temp, idx = 0;
        for (int i = k; i < n; i++) {
            if (grumpy[i - k] == 1) {
                temp -= customers[i - k];
            }
            if (grumpy[i] == 1) {
                temp += customers[i];
            }

            if (maxi < temp) {
                maxi = temp;
                idx = i - k + 1;
            }
        }
        for (int i = idx; i < idx + k; i++) {
            grumpy[i] = 0; 
        }
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }

        return sum;
    }
};

int main(){
    vector<int>customers={1,0,1,2,1,1,7,5};
    vector<int>grumpy={0,1,0,1,0,1,0,1};
    int minutes=3;
    Solution sol;
    cout<<sol.maxSatisfied(customers,grumpy,minutes);
}