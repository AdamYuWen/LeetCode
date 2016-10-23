/*
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 * Examples:
 * s = "leetcode", return 0.
 * s = "loveleetcode", return 2.
 * Note: You may assume the string contain only lowercase letters.
 * https://leetcode.com/problems/first-unique-character-in-a-string/
 *
 * Author: Adam Yu Wen
 * Date: October 6, 2016
 */

class Solution {
public:
	int firstUniqChar(string s) {
		int firstUniqChar(string s) {
			// if there is nothing changed, it returns -1
			int res = -1;

			// create a unordered_map
			unordered_map<char, int> myMap;
			for (int i = 0; i < s.size(); i++) {
				myMap[s.at(i)]++;
			}
			// check all elements to find out the unique element
			for (int i = 0; i < s.size(); i++) {
				if (myMap[s.at(i)] == 1) {
					res = i;
					break;
				}
			}

			return res;
		}
	}
};

