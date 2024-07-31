#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int size = positions.size();
        vector<vector<int>> robots;

        for (auto i = 0; i < size; ++i)
        {
            robots.push_back({positions[i], healths[i], directions[i],i});
        }

        sort(robots.begin(), robots.end());

        vector<vector<int>> stack;

        for (auto& robot : robots)
        {
            if (robot[2] == 'R' || stack.empty() || stack.back()[2] == 'L')
            {
                stack.push_back(robot);
                continue;
            }
            if (robot[2] == 'L')
            {
                bool add = true;
                while (!stack.empty() && stack.back()[2] == 'R' && add)
                {
                    int last_health = stack.back()[1];
                    if (robot[1] > last_health)
                    {
                        stack.pop_back();
                        robot[1] -= 1;
                    }
                    else if (robot[1] < last_health)
                    {
                        stack.back()[1] -= 1;
                        add = !add;
                    }
                    else
                    {
                        stack.pop_back();
                        add = !add;
                    }
                }
                if (add)
                {
                    stack.push_back(robot);
                }
            }
        }
        vector<int> result;
        sort(stack.begin(), stack.end(), [](vector<int> &a, vector<int> &b)
             { return a[3] < b[3]; });

        for (auto &robot : stack)
        {
            result.push_back(robot[1]);
        }

        return result;
    }
};

int main()
{
    vector<int> positions, healths;
    string directions;
    positions = {5, 4, 3, 2, 1};
    healths = {2, 17, 9, 15, 10};
    directions = "RRRRR";

    Solution sol;
    vector<int> result = sol.survivedRobotsHealths(positions, healths, directions);
    cout << "Before Collision:";
    for (auto i : healths)
    {
        cout << i << " ";
    }
    cout << endl
         << "After Collision:";
    for (auto i : result)
    {
        cout << i << " ";
    }
}
