#include<iostream>
using namespace std;
#include<math.h>

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[101][101] = {1};  
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x <= min(j, i - 1); x++) {
                    
                    if (j - x >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;
                    }
                }
            }
        }

        return dp[n][k];
    }
};

int main(){
    Solution solution;

    int n=4,k=1;

    int result=solution.kInversePairs(n,k);
    cout<<result;
}