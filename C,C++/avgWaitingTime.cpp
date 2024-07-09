#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double answer=0;
        int crrTime=0;
        for(auto customer:customers){
            int arrival=customer[0];
            int service=customer[1];
            if(crrTime<arrival){
                crrTime=arrival;
            }
            int waiting_time=crrTime-arrival+service;
            answer+=waiting_time;
            crrTime+=service;
        }
        return answer/customers.size();
    }
};

int main(){
    Solution sol;
    vector<vector<int>>customers={{1,2},{2,5},{4,3}};
    cout<<sol.averageWaitingTime(customers);
}