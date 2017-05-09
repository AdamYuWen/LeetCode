/**
 * Given an integer, return its base 7 string representation.
 * Example 1:
 *      Input: 100
 *      Output: "202"
 * Example 2:
 *      Input: -7
 *      Output: "-10"
 * Note: The input will be in range of [-1e7, 1e7].
 * https://leetcode.com/problems/base-7/#/description
 *
 * Author: Adam Yu Wen
 * Date: May 05, 2017
 */

class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        if (num == 0) res.append(std::to_string(0));
        else {
            int tempNum = num;
            if (num < 0) {
                res.append("-");
                tempNum = -num;
            }
            int highestpower = 0;
            // Find the highestpower of 7
            while (pow(7, highestpower) <= tempNum) {
                highestpower++;
            }
            
            // For loop for each power of 7
            for (int index = highestpower - 1; index > -1; index--) {
                int multipler = 0;
                // Find the number in each position
                while (multipler * pow(7, index) <= tempNum) {
                    multipler++;
                }
                tempNum -= (multipler - 1) * pow(7, index);
                res.append(std::to_string(multipler - 1));
            }
        }
        return res;
    }
};
