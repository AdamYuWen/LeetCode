/**
 * Given an array of integers A and let n to be its length.
 * Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:
 * F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
 * Calculate the maximum value of F(0), F(1), ..., F(n-1).
 * Note: n is guaranteed to be less than 105.
 * Example: A = [4, 3, 2, 6]
 * F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
 * F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
 * F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
 * F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
 * So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
 * https://leetcode.com/problems/rotate-function/
 *
 * Author: Adam Yu Wen
 * Date: November 2, 2016
 */

class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int sum = 0, F_initial = 0, maxRes = 0;
		int ASize = A.size();
		for (int i = 0; i < ASize; i++) {
			sum += A.at(i);
			F_initial += i * A.at(i);
		}
		for (int i = 0; i < ASize; i++) {
			if (i == 0) maxRes = F_initial;
			else {
				int sumTemp = F_initial + sum - ASize * A[ASize - i];
				F_initial = sumTemp;
				maxRes = max(sumTemp, maxRes);
			}
		}
		return maxRes;
	}
};