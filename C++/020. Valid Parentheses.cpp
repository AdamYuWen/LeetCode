/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * Author: Adam Yu Wen
 * Date: December 19, 2017
 */

bool isValid(string s) {
	int length;
	do {
		// Remove any (), [], or {}
		length = s.length();
		size_t found = s.find("()");
		if (found != string::npos) {
			s = s.erase(found, 2);
		}

		found = s.find("[]");
		if (found != string::npos) {
			s = s.erase(found, 2);
		}

		found = s.find("{}");
		if (found != string::npos) {
			s = s.erase(found, 2);
		}
	} while (length != s.length());

	return length == 0;
}

// The fastest solution from LeetCode:
class Solution {
public:
	bool isClosing(char c) {
		return (c == '}' || c == ']' || c == ')');
	}

	bool isOpening(char c) {
		return (c == '{' || c == '[' || c == '(');
	}

	bool isValid(string s) {
		std::stack<char> my_stack;
		for (int i = 0; i < s.length(); i++) {
			if (isOpening(s[i]))
				my_stack.push(s[i]);
			else if (isClosing(s[i]) && !my_stack.empty()) {
				if (s[i] == '}' && my_stack.top() != '{')
					return false;
				else if (s[i] == ')' && my_stack.top() != '(')
					return false;
				else if (s[i] == ']' && my_stack.top() != '[')
					return false;
				else
					my_stack.pop();
			}
			else
				return false;
		}
		if (my_stack.empty())
			return true;
		return false;


	}
};
