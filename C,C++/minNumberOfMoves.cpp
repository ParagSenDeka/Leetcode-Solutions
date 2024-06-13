#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int moves=0;
        for(int i=0;i<seats.size();i++){
            moves+=abs(seats[i]-students[i]);
        }
        return moves;
    }
};

int main(){
    vector<int>seats={1,3,4,6};
    vector<int>students={1,2,5,4};
    Solution sol;
    cout<<sol.minMovesToSeat(seats,students);
}