#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        std::set<int> outEdgesFound;

        for (const auto& edge : edges) {
            if (outEdgesFound.find(edge[0]) != outEdgesFound.end()) {
                return edge[0];
            }
            outEdgesFound.insert(edge[0]);

            if (outEdgesFound.find(edge[1]) != outEdgesFound.end()) {
                return edge[1];
            }
            outEdgesFound.insert(edge[1]);
        }

        return -1;
    }
};

int main() {
    Solution solution;

    std::vector<std::vector<int>> edges1 = {{1, 2}, {2, 3}, {4, 2}};
    int center1 = solution.findCenter(edges1);
    if (center1 != -1) {
        std::cout << "Center vertex of the graph is: " << center1 << std::endl;
    } else {
        std::cout << "No center vertex found." << std::endl;
    }

    return 0;
}

