/*
 * Given a string, you need to reverse the order of characters in each word within
 * a sentence while still preserving whitespace and initial word order.
 * Example 1:
 *	Input: "Let's take LeetCode contest"
 *	Output: "s'teL ekat edoCteeL tsetnoc"
 * Note: In the string, each word is separated by single space and there will not
 * be any extra space in the string.
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * Author: Adam Yu Wen
 * Date: December 21, 2017
 */

class Solution {
public:
	string reverseWords(string s) {
		string res = s;
		size_t found = s.find_first_of(" ");

		int start = 0;
		while (found != string::npos) {
			res.replace(start, found - start, reverseString(s.substr(start, found - start)));
			start = found + 1;
			found = s.find(" ", found + 1);
		}

		// reverse the last word OR reverse the only word
		res.replace(start, s.size() - start, reverseString(s.substr(start, s.size() - start)));
		return res;
	}

	string reverseString(string s) {
		int first = 0;
		int second = s.size() - 1;
		while (first < second) {
			char temp = s[first];
			s[first] = s[second];
			s[second] = temp;
			first++;
			second--;
		}
		return s;
	}
};