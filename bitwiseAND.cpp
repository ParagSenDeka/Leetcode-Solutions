#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (left != right) {
            left >>= 1;
            cout<<left<<endl;
            right >>= 1;
            cout<<right<<endl;
            cnt++;
        }
        return (right << cnt);

    }
};

int main(){
    Solution solution;
    cout<<solution.rangeBitwiseAnd(5,7);
}