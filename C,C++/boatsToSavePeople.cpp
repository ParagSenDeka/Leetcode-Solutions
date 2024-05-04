#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        std::cout<<"Called";
        int boat = 0;
        int start = 0, end = people.size() - 1;
        while (start <= end) {
            if (people[start] + people[end] <= limit) {
                boat++;
                start++;
                end--;
            }
            else{
                boat++;
                end--;
            }
        }
        return boat;
    }
};

int main(){
    Solution solution;
    std::vector<int> people={1,2};
    int limit=3;
    std::cout<<solution.numRescueBoats(people,limit);
}