/**
 * Given a positive integer, return its corresponding
 * column title as appear in an Excel sheet.
 * For example:
 *  1 -> A
 *  2 -> B
 *  3 -> C
 *  ...
 *  26 -> Z
 *  27 -> AA
 *  28 -> AB
 *
 * Author: Adam Yu Wen
 * Date: July 11, 2017
 */

class Solution {
public:
    string convertToTitle(int n) {
        int quotient = n;
        int remainder;
        string res = "";

        while(quotient != 0) {
            remainder = quotient % 26;
            // If the remainder is 26
            // the char in line 32 should be 26+64 instead of 0+64
            if(remainder == 0) {
                remainder = 26;
                quotient -= 26;
            }
            quotient /= 26;
            res.insert(res.begin(), 1, char(remainder + 64));
        }
        return res;
    }
};
