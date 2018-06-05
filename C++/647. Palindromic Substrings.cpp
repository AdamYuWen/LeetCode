/* Given a string, your task is to count how many palindromic substrings in this string.
 * The substrings with different start indexes or end indexes are counted as different
 * substrings even they consist of same characters.
 * Example 1:
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * Example 2:
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * Note:
 * The input string length won't exceed 1000.
 * https://leetcode.com/problems/palindromic-substrings/description/
 * 
 * Author: Adam Yu Wen
 * Date: June 5, 2018
 */

// It is slow, which takes 204 ms, beats 10.24% of cpp submissions.
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        // The size of substrings
        for (int i = 1; i < s.size() + 1; i++) {
            // Different substrings with the same size
            for (int j = 0; j < s.size() - i + 1; j++) {
                if (palindromic(s.substr(j, i))) {
                    res++;
                }
            }
        }
        return res;
    }
    
    bool palindromic(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
