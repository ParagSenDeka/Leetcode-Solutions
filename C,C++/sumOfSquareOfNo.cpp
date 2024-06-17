#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a=0;a*a<c;a++){
            double b=sqrt(c-a*a);
            if(b==int(b)){
                return true;
            }
        }
        return false;
    }
};
int main(){
    int c=5;
    Solution sol;
    cout<<sol.judgeSquareSum(c);
}