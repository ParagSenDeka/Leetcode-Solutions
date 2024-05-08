#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>sortedScore=score;
        sort(sortedScore.begin(),sortedScore.end(),greater<int>());
        vector<string>medals={"Gold Medal","Silver Medal","Bronze Medal"};
        unordered_map<int,string>storedValue;
        for(int i=0;i<sortedScore.size();i++){
            (i<3)?storedValue[sortedScore[i]]=medals[i]:storedValue[sortedScore[i]]=to_string(i+1);
        }
        vector<string>result;
        for(auto i:score){
            result.push_back(storedValue[i]);
        }
        return result;
    }
};

int main(){
    vector<int>score={4,2,4,1,7};
    Solution sol;
    vector<string>solution=sol.findRelativeRanks(score);
    cout<<solution[0];
    for(int i=1;i<solution.size();i++){
        cout<<","<<solution[i];
    }
    return 0;
}