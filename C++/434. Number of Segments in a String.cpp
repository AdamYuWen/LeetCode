/**
 * Count the number of segments in a string, where a segment is defined to
 * be a contiguous sequence of non-space characters.
 * Please note that the string does not contain any non-printable characters.
 * Example:
 *	Input: "Hello, my name is John"
 *	Output: 5
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * Author: Adam Yu Wen
 * Date: March 1, 2018
 */

class Solution {
public:
	int countSegments(string s) {
		// The specifical case 
		if (s == "") return 0;

		int res = 1;
		size_t found = s.find(' ');
		// If the first char is a space, find from the second char
		if (s[0] == ' ') found = s.find(' ', 1);
		while (found != string::npos) {
			if (s[found - 1] != ' ') {
				res++;
			}
			found = s.find(' ', found + 1);
		}
		// If the last is a space, reduce res by one
		if (s[s.size() - 1] == ' ') res--;
		return res;
	}
};