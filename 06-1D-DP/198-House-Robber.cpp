/*
 * Problem 198: House Robber
 * Time Complexity: O(N) - We iterate through the array of houses exactly once.
 * Space Complexity: O(1) - We only store the two previous maximum profits.
 * Note: Dynamic Programming with state reduction.
 */

#include <algorithm>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int current, prev1, prev2;
        int nSize = nums.size();
        if (nSize <= 0)
            return 0;
        else if (nSize == 1)
            return nums[0];
        prev2 = nums[0];
        prev1 = std::max(nums[0], nums[1]);
        for (int i = 2; i < nSize; ++i) {
            current = std::max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};