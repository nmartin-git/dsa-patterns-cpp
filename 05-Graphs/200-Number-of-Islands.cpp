/*
 * Problem 200: Number of Islands
 * Time Complexity: O(M * N) - Every cell in the grid is visited a constant number of times.
 * Space Complexity: O(M * N) - Worst-case recursion stack depth if the entire grid is filled with land.
 * Note: Graph traversal using recursive DFS. Island sinking strategy with universal bounds-checking base case.
 */

#include <vector>

class Solution {
public:
    void dfs(std::vector<std::vector<char>>& grid, int r, int c) {
         if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
             return ;
         grid[r][c] = '0';
         dfs(grid, r, c + 1);
         dfs(grid, r + 1, c);
         dfs(grid, r, c - 1);
         dfs(grid, r - 1, c);
         return ;
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int iSize;
        int ySize = grid.size();
        int islandsCount = 0;

        for (int y = 0; y < ySize; ++y)
        {
             iSize = grid[y].size();
             for (int i = 0; i < iSize; ++i)
             {
                  if (grid[y][i] == '1') {
                      dfs(grid, y, i);
                      ++islandsCount;
                  }
              }
        }
        return islandsCount;
    }
};