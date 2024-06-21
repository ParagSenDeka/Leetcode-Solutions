#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
          sort(position.begin(),position.end());
          int n=position.size();
          int l=0;
          int r=1e9;

          int crrMax=0;
          while(l<=r){
            int mid=(l+r)/2;
            if(isValid(mid,position)>=m){
                l=mid+1;
                crrMax=max(crrMax,mid);
            }
            else{
                r=mid-1;
            }
          }
          return crrMax;
    }
    int isValid(int mid,vector<int>position){
        int total=1;
        int crrDist=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-crrDist>=mid){
                total++;
                crrDist=position[i];
            }
        }
        return total;
    }
};

int main(){
    vector<int>position={4,3,2,1,10000};
    int m=2;
    Solution sol;
    cout<<sol.maxDistance(position,m);
}