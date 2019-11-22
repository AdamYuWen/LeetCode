/* Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be
 * a substring, "pwke" is a subsequence and not a substring.
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * Author: Adam Yu Wen
 * Date: June 26, 2018
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // res is the result of this function
        // left is the left point of a substring
        int res = 0, left = 0;
        int map[256] = {0};
        
        // visit all characters in the string s
        for (int i = 0; i < s.length(); i++) {
            // if the character is 0, add 1 to result
            // if the character is at the left side of left, which means that we didn't
            // count the char, we should add the char to the substring
            if (map[s[i]] == 0 || map[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                // move the left
                left = map[s[i]];
            }
            map[s[i]] = i + 1;
        }
        return res;
    }
};
