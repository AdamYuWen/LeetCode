/* Determine whether an integer is a palindrome. Do this without extra space.
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * Author: Adam Yu Wen
 * Date: March 1, 2018
 */

class Solution {
public:
 	bool isPalindrome(int x) {
		if (x < 0) return false;
        int div = 1;
        int xTmp = x;
		while (xTmp > 9) {
            div *= 10;
            xTmp /= 10;
		}
		while (x > 0) {
            int high = x / div;
            int low = x % 10;
			if (high != low) return false;
			x = (x - high * div) / 10;
			div /= 100;
		}
		return true;
	}
};
