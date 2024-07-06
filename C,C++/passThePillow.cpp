#include<iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int N=2*n-2, x=time%N;
        return 1+((x<n)?x:N-x);
        
    }
};

int main(){
    Solution sol;
    cout<<sol.passThePillow(4,5);
}