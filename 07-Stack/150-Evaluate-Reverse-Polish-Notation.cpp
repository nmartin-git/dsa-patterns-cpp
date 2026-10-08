/*
 * Problem 150: Evaluate Reverse Polish Notation
 * Time Complexity: O(N) - We iterate through the vector exactly once.
 * Space Complexity: O(N) - In the worst case, the stack stores N/2 + 1 numbers.
 * Note: Use a stack. Push numbers, pop two for operators, push result. Order matters for division and subtraction.
 */

#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> numbers;
        int tSize = tokens.size();
        int tmp1;
        int tmp2;

        for (int i = 0; i < tSize; ++i) {
            if (tokens[i].size() == 1 && !std::isdigit(tokens[i][0])) {
                tmp1 = numbers.top();
                numbers.pop();
                tmp2 = numbers.top();
                numbers.pop();
                if (tokens[i][0] == '+')
                    numbers.push(tmp2 + tmp1);
                else if (tokens[i][0] == '-')
                    numbers.push(tmp2 - tmp1);
                else if (tokens[i][0] == '/')
                    numbers.push(tmp2 / tmp1);
                else if (tokens[i][0] == '*')
                    numbers.push(tmp2 * tmp1);
            }
            else
                numbers.push(std::atoi(tokens[i].c_str()));
        }
        return numbers.top();
    }
};