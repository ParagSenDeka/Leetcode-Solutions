#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1')
                {
                    islands++;
                    bfs(grid, r, c, rows, cols);
                }
            }
        }

        return islands;
    }

private:
    void bfs(vector<vector<char>> &grid, int r, int c, int rows, int cols)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions)
            {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1')
                {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout << sol.numIslands(grid);
}