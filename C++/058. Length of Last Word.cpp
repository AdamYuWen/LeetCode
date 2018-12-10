/* Given a string s consists of upper/lower-case alphabets
 * and empty space characters ' ', return the length of last
 * word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists
 * of non-space characters only.
 * For example,
 * Given s = "Hello World",
 * return 5.
 *
 * Author: Adam Yu Wen
 * Date: July 07, 2017
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s == "") return 0;

        int res = 0;
        int idx = s.size() - 1;
        // Ignore all space at the end of the string
        while(idx > -1 && s[idx] == ' ') idx--;
        // Count the size of length of the last word until a space
        while(idx > -1 && s[idx] != ' ') {
            res++;
            idx--;
        }
        return res;
    }
};
