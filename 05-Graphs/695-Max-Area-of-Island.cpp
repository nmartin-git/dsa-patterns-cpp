/*
 * Problem 695: Max Area of Island
 * Time Complexity: O(M * N) - We visit every cell in the grid.
 * Space Complexity: O(M * N) - Worst-case recursion stack space if the grid is filled with land.
 * Note: DFS traversal calculating the size of connected components. State mutation used for visited cells.
 */

#include <algorithm>
#include <vector>

class Solution {
public:
    int dfs(std::vector<std::vector<int>>& grid, int r, int c) {
        int islandSize = 1;
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
           return 0;
        grid[r][c] = 0;
        islandSize += dfs(grid, r, c + 1);
        islandSize += dfs(grid, r, c - 1);
        islandSize += dfs(grid, r + 1, c);
        islandSize += dfs(grid, r - 1, c);
        return islandSize;
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int cSize;
        int rSize = grid.size();
        int maxArea = 0;
        for (int r = 0; r < rSize; ++r) {
            cSize = grid[r].size();
            for (int c = 0; c < cSize; ++c) {
                if (grid[r][c] == 1)
                   maxArea = std::max(dfs(grid, r, c), maxArea);
            }
        }
        return maxArea;
    }
};