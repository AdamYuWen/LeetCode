/**
 * Given a non-empty string check if it can be constructed by taking a substring of it
 * and appending multiple copies of the substring together. You may assume the given
 * string consists of lowercase English letters only and its length will not exceed 10000.
 * Example 1:
 *	Input: "abab"
 *	Output: True
 *	Explanation: It's the substring "ab" twice.
 * Example 2:
 *	Input: "aba"
 *	Output: False
 * Example 3:
 *	Input: "abcabcabcabc"
 *	Output: True
 *	Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * Author: Adam Yu Wen
 * Date: March 1, 2018
 */

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int numSize = s.size();
		for (int subStrSize = numSize / 2; subStrSize > 0; subStrSize--) {
			if (numSize % subStrSize == 0) {
				string compareAttempt;
				for (int idx = 0; idx < numSize / subStrSize; idx++) {
					compareAttempt += s.substr(0, subStrSize);
				}
				if (compareAttempt == s) return true;
			}
		}
		return false;
	}
};