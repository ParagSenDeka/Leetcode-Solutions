#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int>in(N+1),out(N+1);
        for(int i=0;i<trust.size();++i){
            auto a=trust[i];
            ++out[a[0]];
            ++in[a[1]];
        }

        for(int i=0;i<=N;i++){
            if(in[i]==N-1 && out[i]==0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>>trust={{1,3},{2,3}};
    int N=3;
    Solution solution;
    cout<<solution.findJudge(N,trust);
}