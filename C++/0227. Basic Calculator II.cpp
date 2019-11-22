/* Implement a basic calculator to evaluate a simple expression string.
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces . The integer division should truncate toward zero.
 * Example 1:
 * Input: "3+2*2"
 * Output: 7
 * Example 2:
 * Input: " 3/2 "
 * Output: 1
 * Example 3:
 * Input: " 3+5 / 2 "
 * Output: 5
 * Note:
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * https://leetcode.com/problems/basic-calculator-ii/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 17, 2018
 */

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> nums;
        char op = '+';

        int sSize = s.size();
        int num = 0;
        for (int idx = 0; idx < sSize; idx++) {
            if (s[idx] >= '0') {
                num = num * 10 + (s[idx] - '0');
            }
            else if (s[idx] == ' ' && idx != sSize - 1) continue;
            if (s[idx] < '0' || idx == sSize - 1) {
                if (op == '+') {
                    nums.push(num);
                }
                else if (op == '-') {
                    nums.push(-num);
                }
                else if (op == '*') {
                    int tmp = nums.top();
                    nums.pop();
                    nums.push(tmp * num);
                }
                else if (op == '/') {
                    int tmp = nums.top();
                    nums.pop();
                    nums.push(tmp / num);
                }
                op = s[idx];
                num = 0;
            }
        }

        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};
