/**
 * A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 * For example, these are arithmetic sequence:
 * 		1, 3, 5, 7, 9
 *		7, 7, 7, 7
 *		3, -1, -5, -9
 * The following sequence is not arithmetic.
 *		1, 1, 2, 5, 7
 * A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
 * The function should return the number of arithmetic slices in the array A.
 * Example:
 * A = [1, 2, 3, 4]
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 * https://leetcode.com/problems/arithmetic-slices/
 *
 * Author: Adam Yu Wen
 * Date: November 1, 2016
 */

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3) return 0;

		int res = 0, len = 2;
		// set len to 2 because if len >= 3 it is an arithmetic
		// in addition, when len is 2, (1 + len * (len - 3) / 2) is 0
		// if there are n element in an arithmetic, the number of slices is
		// a_n = a_(n-1) + n - 2
		for (int i = 2; i < A.size(); i++) {
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
				len++;
			}
			else {
				res += 1 + len * (len - 3) / 2;
				len = 2;
			}
		}
		res += 1 + len * (len - 3) / 2;
		return res;
	}
};