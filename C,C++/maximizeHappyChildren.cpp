#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long answer = 0;
        int turns=0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i=0;i<k;i++){
            answer+=max(happiness[i]-turns,0);
            turns++;
        }
        return answer;
    }
};

int main(){
    vector<int>happiness={4,2,4,1,7};
    int k=2;
    Solution sol;
    cout<<sol.maximumHappinessSum(happiness,k);
    return 0;
}