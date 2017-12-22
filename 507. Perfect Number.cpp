/* We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
 * Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
 * Example:
 *	Input: 28
 *	Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * Note: The input number n will not exceed 100,000,000. (1e8)
 * https://leetcode.com/problems/perfect-number/description/
 *
 * Author: Adam Yu Wen
 * Date: December 21, 2017
 */

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num == 0) return false;

		int sumDividors = 0;
		int first = 1;
		int second = num;
		while (first < second) {
			if (num % first == 0) {
				sumDividors += (first + second);
			}
			first++;
			second = num / first;
		}
		return num == sumDividors - num;
	}
};