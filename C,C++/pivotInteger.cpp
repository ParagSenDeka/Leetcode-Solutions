#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int sum=n*(n+1)/2;
        double a=sqrt(sum);
        if(a-ceil(a)==0){
            return a;
        }
        else{
            return -1;
        }
    }
};

int main(){
    int n=8;
    Solution solution;
    cout<<solution.pivotInteger(n);
}