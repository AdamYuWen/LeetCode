/**
 * Write a program that outputs the string representation of numbers from 1 to n.
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
 * Example: n = 15,
 * Return:
 *	[
 *		"1",
 *		"2",
 *		"Fizz",
 *		"4",
 *		"Buzz",
 *		"Fizz",
 *		"7",
 *		"8",
 *		"Fizz",
 *		"Buzz",
 *		"11",
 *		"Fizz",
 *		"13",
 *		"14",
 *		"FizzBuzz"
 *	]
 * https://leetcode.com/problems/fizz-buzz/
 *
 * Author: Adam Yu Wen
 * Date: October 28, 2016
 */

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> res;
		for (int i = 0; i < n; i++) {
			if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
				res.push_back("FizzBuzz");
			}
			else if ((i + 1) % 3 == 0) {
				res.push_back("Fizz");
			}
			else if ((i + 1) % 5 == 0) {
				res.push_back("Buzz");
			}
			else {
				res.push_back(to_string(i + 1));
			}
		}
		return res;
	}
};