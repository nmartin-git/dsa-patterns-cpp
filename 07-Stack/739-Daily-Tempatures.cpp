/*
 * Problem 739: Daily Temperatures
 * Time Complexity: O(N) - Every index is pushed and popped at most once.
 * Space Complexity: O(N) - In the worst case (strictly decreasing temperatures), the stack holds N elements.
 * Note: Monotonic decreasing stack storing indices.
 */

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> s;
        int prevDayIndex;
        int tSize = temperatures.size();
        std::vector<int> res(tSize, 0);

        for (int i = 0; i < tSize; ++i) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                prevDayIndex = s.top();
                s.pop();
                res[prevDayIndex] = i - prevDayIndex;
            }
            s.push(i);
        }
        return res;
    }
};