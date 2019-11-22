/* Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * Author: Adam Yu Wen
 * Date: November 19, 2016
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> myMap = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        int res = 0, strSize = s.size();
        // if the string has only one char, return the value
        if (strSize == 1) return myMap[s.at(0)];
        // if the string has more than one char
        for (int i = 0; i < strSize - 1; i++) {
            if (myMap[s[i]] < myMap[s[i + 1]]) {
                res -= myMap[s[i]];
            } else {
                res += myMap[s[i]];
            }
            // add the last character
            if (i == strSize - 2) {
                res += myMap[s[i + 1]];
            }
        }
        return res;
    }
};
