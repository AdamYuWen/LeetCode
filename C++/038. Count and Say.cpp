/*
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * Note: Each term of the sequence of integers will be represented as a string.
 *
 * Example 1:
 *	  Input: 1
 *	  Output: "1"
 * Example 2:
 *	  Input: 4
 *	  Output: "1211"
 * https://leetcode.com/problems/count-and-say/description/
 *
 * Author: Adam Yu Wen
 * Date: March 2, 2018
 */

class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) return "1";

		string prevStr = "1";
		string currStr = "";
		for (int idxSeq = 1; idxSeq < n; idxSeq++) {
			int sizePre = prevStr.size();
			char currChar;
			int count = 1;
			for (int idxPre = 0; idxPre < sizePre; idxPre++) {
				if (prevStr[idxPre] == prevStr[idxPre + 1]) count++;
				else {
					currStr += to_string(count);
					currStr += prevStr[idxPre];
					count = 1;
				}
			}
			prevStr = currStr;
			currStr = "";
		}
		return prevStr;
	}
};