#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    long countSteps(long n, long prefix)
    {
        long current = prefix;
        long nextPrefix = prefix + 1;
        long steps = 0;

        while (current <= n)
        {
            steps += min(n + 1, nextPrefix) - current;
            current *= 10;
            nextPrefix *= 10;
        }

        return steps;
    }

public:
    int findKthNumber(int n, int k)
    {
        long current = 1;
        k--;

        while (k > 0)
        {
            long steps = countSteps(n, current);

            if (steps <= k)
            {
                k -= steps;
                current++;
            }
            else
            {
                current *= 10;
                k--;
            }
        }

        return current;
    }
};

int main()
{
    Solution sol;
    cout << sol.findKthNumber(13, 13);
}