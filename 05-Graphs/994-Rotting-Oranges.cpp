/*
 * Problem 994: Rotting Oranges
 * Time Complexity: O(M * N) - We visit each cell in the grid at most once.
 * Space Complexity: O(M * N) - In the worst case, the queue can store all cells.
 * Note: Multi-source BFS using a queue to track rotten oranges. Size-locking is used to track minutes.
 */

#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int cSize, x, y, xNew, yNew;
        int freshNbr = 0;
        int minsNbr = 0;
        int rSize = grid.size();
        int qSize;
        std::queue<std::pair<int, int>> q;
        std::vector<std::pair<int,int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int r = 0; r < rSize; ++r) {
            cSize = grid[r].size();
            for (int c = 0; c < cSize; ++c) {
                if (grid[r][c] == 1)
                    ++freshNbr;
                else if (grid[r][c] == 2)
                    q.push({r, c});
            }
        }
        while (!q.empty())
        {
            qSize = q.size();
            ++minsNbr;
            while (--qSize >= 0) {
                y = q.front().first;
                x = q.front().second;
                q.pop();
                for (const auto& dir: directions) {
                    yNew = y + dir.first;
                    xNew = x + dir.second;
                    if (yNew < 0 || xNew < 0 || yNew >= rSize || xNew >= cSize || grid[yNew][xNew] != 1)
                        continue ;
                    grid[yNew][xNew] = 2;
                    if (--freshNbr <= 0)
                        return minsNbr;
                    q.push({yNew, xNew});
                }
            }
        }
        if (freshNbr > 0)
            return -1;
        return 0;
    }
};