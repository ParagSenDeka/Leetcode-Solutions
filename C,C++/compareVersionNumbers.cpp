#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    
    int compareVersion(std::string version1, std::string version2) {
        int i=0;
        int j=0;
        std::vector<int> res1,res2;
        while(i<version1.size() || j<version2.size()){
            res1=helper(version1,i);
            res2=helper(version2,j);
            int v1=res1[0],v2=res2[0];
            i=res1[1],j=res2[1];
            if(v1>v2){
                return 1;
            }else if(v1<v2){
                return -1;
            }
        }
        return 0;
    }
    std::vector<int> helper(std::string s,int idx){
        int num=0;
        while(idx<s.size()){
            if(s[idx]=='.'){
                break;
            }else{
                num=num*10+(s[idx]-'0');
                idx++;
            }
        }
        return {num,idx+1};
    }

};

int main(){
    Solution solution;
    std::string version1="1.0.1",version2="0.2.0";
    std::cout<<solution.compareVersion(version1,version2);
}