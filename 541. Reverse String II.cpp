/*Given a string and an integer k, you need to reverse the first k characters for every
 * 2k characters counting from the start of the string. If there are less than k characters
 * left, reverse all of them. If there are less than 2k but greater than or equal to k
 * characters, then reverse the first k characters and left the other as original.
 * Example:
 *	Input: s = "abcdefg", k = 2
 *	Output: "bacdfeg"
 * Restrictions:
 *	The string consists of lower English letters only.
 *	Length of the given string and k will in the range [1, 10000]
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * Author: Adam Yu Wen
 * Date: December 21, 2017
 */

class Solution {
public:
	string reverseStr(string s, int k) {
		if (s.size() < k) {
			s = reverseString(s);
		}
		else if (s.size() < 2 * k) {
			s.replace(s.begin(), s.begin() + k, reverseString(s.substr(0, k)));
		}
		else {
			int numTwiceK = s.size() / 2 / k;
			int left = s.size() % (2 * k);
			if (left >= k) {
				numTwiceK++;
				for (int idx = 0; idx < numTwiceK; idx++) {
					int start = idx * 2 * k;
					s.replace(s.begin() + start, s.begin() + start + k, reverseString(s.substr(start, k)));
				}
			}
			else {
				for (int idx = 0; idx < numTwiceK; idx++) {
					int start = idx * 2 * k;
					s.replace(s.begin() + start, s.begin() + start + k, reverseString(s.substr(start, k)));
				}
				int lastStart = numTwiceK * 2 * k;
				s.replace(s.begin() + lastStart, s.end(), reverseString(s.substr(lastStart, s.size() - lastStart)));
			}
		}
		return s;
	}

	string reverseString(string s) {
		int first = 0;
		int second = s.size() - 1;
		string res = s;
		while (first < second) {
			char temp = res[first];
			res[first] = res[second];
			res[second] = temp;
			first++;
			second--;
		}
		return res;
	}
};