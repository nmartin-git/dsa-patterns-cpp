/*
 * Problem 417: Pacific Atlantic Water Flow
 * Time Complexity: O(M * N) - Each cell is visited at most once by the Pacific DFS and once by the Atlantic DFS.
 * Space Complexity: O(M * N) - For the boolean reachability matrices and the recursion stack.
 * Note: Uses reverse DFS from the ocean boundaries to find reachable landmasses.
 */

#include <vector>

class Solution {
public:
    void dfs(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& reachable, int r, int c) {
        if (reachable[r][c])
            return ;
        reachable[r][c] = true;
        if (c + 1 < heights[0].size() && heights[r][c] <= heights[r][c + 1])
            dfs(heights, reachable, r, c + 1);
        if (c - 1 >= 0 && heights[r][c] <= heights[r][c - 1])
            dfs(heights, reachable, r, c - 1);
        if (r + 1 < heights.size() && heights[r][c] <= heights[r + 1][c])
            dfs(heights, reachable, r + 1, c);
        if (r - 1 >= 0 && heights[r][c] <= heights[r - 1][c])
            dfs(heights, reachable, r - 1, c);
        return;
    }

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        std::vector<std::vector<int>> resTab;
        int rSize = heights.size(), cSize = heights[0].size();
        std::vector<std::vector<bool>> pacificReachable(rSize, std::vector<bool>(cSize, false));
        std::vector<std::vector<bool>> atlanticReachable(rSize, std::vector<bool>(cSize, false));

        for (int r = 0; r < rSize; ++r) {
            dfs(heights, pacificReachable, r, 0);
            dfs(heights, atlanticReachable, r, cSize - 1);
        }
        for (int c = 0; c < cSize; ++c) {
            dfs(heights, pacificReachable, 0, c);
            dfs(heights, atlanticReachable, rSize - 1, c);
        }
        for (int y = 0; y < rSize; ++y) {
            for (int x = 0; x < cSize; ++x) {
                if (pacificReachable[y][x] && atlanticReachable[y][x])
                    resTab.push_back({y, x});
            }
        }
        return resTab;
    }
};