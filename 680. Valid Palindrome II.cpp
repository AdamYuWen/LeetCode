/*
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
 * Example 1:
 *	  Input: "aba"
 *	  Output: True
 * Example 2:
 *	  Input: "abca"
 *	  Output: True
 *	  Explanation: You could delete the character 'c'.
 * Note:
 * The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * Author: Adam Yu Wen
 * Date: November 2, 2016
 */

class Solution {
public:
	bool validPalindrome(string s) {
		int first = 0; int second = s.length() - 1;
		bool flag = false;	// it allows for deleting at most one character
		while (first < second) {
			if (s[first] == s[second]) {
				first++;
				second--;
			}
			else if (flag == true) {
				return false;
			}
			else {
				if (s[first + 1] == s[second] && s[first] != s[second - 1]) {
					first += 2;
					second--;
					flag = true;
				}
				else if (s[first] == s[second - 1] && s[first + 1] != s[second]) {
					first++;
					second -= 2;
					flag = true;
				}
				else if (s[first + 1] == s[second] && s[first] == s[second - 1]) {
					// If in this situation, the problem branched to two.
					string newSLeft;
					string newSRigh;
					newSLeft = s.substr(first, second - first);
					newSRigh = s.substr(first + 1, second - first);

					first = 0; second = newSLeft.size() - 1;
					while (first < second) {
						if (newSLeft[first] != newSLeft[second]) {
							first = 0; second = newSRigh.size() - 1;
							while (first < second) {
								if (newSRigh[first] != newSRigh[second]) {
									return false;
								}
								else {
									first++;
									second--;
								}
							}
						}
						else {
							first++;
							second--;
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
};