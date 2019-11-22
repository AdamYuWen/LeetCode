/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 * Example 1:
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * Example 2:
 * Input: "race a car"
 * Output: false
 * https://leetcode.com/problems/valid-palindrome/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 10, 2018
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int sSize = s.size();
        int l = 0, r = sSize - 1;
        while (l < r) {
            // Only alphanumeric characters
            while (!isalnum(s[l]) && l < r) l++;
            while (!isalnum(s[r])) r--;
            
            // Turn the capital letters to lower cases
            if (int(s[l]) >= int('A') && int(s[l]) <= int('Z')) {
                s[l] = s[l] + 32;
            }
            if (int(s[r]) >= int('A') && int(s[r]) <= int('Z')) {
                s[r] = s[r] + 32;
            }

            if (l < r && s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
