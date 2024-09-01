#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>result(m,vector<int>(n));

        if (m * n != original.size()) {
            return {};
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[i][j]=original[(i*n)+j];
            }
        }

        return result;
    }
};


int main(){
    Solution sol;
    vector<int>original={1,2,3,4};
    int m=2,n=2;
    auto result=sol.construct2DArray(original,m,n);
    for(auto i:result){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}