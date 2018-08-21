/* Given a balanced parentheses string S, compute the score of the string based on the following rule:
 * () has score 1
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 * Example 1:
 *   Input: "()"
 *   Output: 1
 * Example 2:
 *   Input: "(())"
 *   Output: 2
 * Example 3:
 *   Input: "()()"
 *   Output: 2
 * Example 4:
 *   Input: "(()(()))"
 *   Output: 6
 * Note:
 *   S is a balanced parentheses string, containing only ( and ).
 *   2 <= S.length <= 50
 * https://leetcode.com/problems/score-of-parentheses/description/
 *
 * Author: Adam Yu Wen
 * Date: August 20, 2018
 */

// Method 1: From Leetcode Discussion
class Solution {
public:
    int scoreOfParentheses(string S) {
        int depth = 0, score = 0;
        int SSize = S.size();
        for (int i = 0; i < SSize; i++) {
            S[i] == '(' ? depth += 1 : depth -= 1;
            if (S[i] == ')' && S[i - 1] == '(') {
                score += pow(2, depth);
                cout << score << endl;
            }
        }
        return score;
    }
};


// Method 2: Using stack
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> myStack;
        myStack.push(0);
        for (int i = 0, SSize = S.size(); i < SSize; i++) {
            if (S[i] == '(') {
                myStack.push(0);
            }
            else {                
                int temp = myStack.top();
                myStack.pop();
                if (S[i - 1] == '(') {
                    myStack.top() += 1;
                }
                else {
                    myStack.top() += temp * 2;
                }
            }
        }
        return myStack.top();
    }
};
