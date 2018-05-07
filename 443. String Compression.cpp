/* Given an array of characters, compress it in-place.
 * The length after compression must always be smaller than or equal to the original array.
 * Every element of the array should be a character (not int) of length 1.
 * After you are done modifying the input array in-place, return the new length of the array.
 * Follow up:
 * Could you solve it using only O(1) extra space?
 * Example 1:
 * Input:
 * ["a","a","b","b","c","c","c"]
 * Output:
 * Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
 * Explanation:
 * "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
 * Example 2:
 * Input:
 * ["a"]
 * Output:
 * Return 1, and the first 1 characters of the input array should be: ["a"]
 * Explanation:
 * Nothing is replaced.
 * Example 3:
 * Input:
 * ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * Output:
 * Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
 * Explanation:
 * Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
 * Notice each digit has it's own entry in the array.
 * Note:
 * All characters have an ASCII value in [35, 126].
 * 1 <= len(chars) <= 1000.
 * https://leetcode.com/problems/string-compression/description/
 *
 * Author: Adam Yu Wen
 * Date: May 7, 2018
 */

class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0, r = 0, cnt = 0;
        int charsSize = chars.size();
        int idx = 0;
        
        while (l < charsSize) {
            while (r < charsSize && chars[l] == chars[r]) {
                r++;
                cnt++;
            }
	    // left a char in the vector
            chars[idx++] = chars[l];
	    // put the number at the following
            if (cnt > 1) {
                string cntStr = to_string(cnt);
                int cntStrSize = cntStr.size();
                for (int i = 0; i < cntStrSize; i++) {
                    chars[idx] = cntStr[i];
                    idx++;
                }
                cnt = 0;
            }
            l = r;
	    // if a char appears only one time, the cnt changed to 1
	    // it is necessary to change cnt back to 0
            cnt = 0;
        }
        
        return idx;
    }
};
