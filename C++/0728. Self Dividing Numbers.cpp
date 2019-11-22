/**
 * A self-dividing number is a number that is divisible by every digit it contains.
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * Given a lower and upper number bound, output a list of every possible self
 * dividing number, including the bounds if possible.
 * Example 1:
 *	Input: 
 *	left = 1, right = 22
 *	Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * Note: The boundaries of each input argument are 1 <= left <= right <= 10000.
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * Author: Adam Yu Wen
 * Date: February 28, 2018
 */

class Solution {
public:
	bool selfDividingNumbers(int num) {
		vector<int> singleNum;
		int numTmp = num;
		while (numTmp > 0) {
			if (numTmp % 10 == 0) return false;
			singleNum.push_back(numTmp % 10);
			numTmp /= 10;
		}
		for (unsigned int idx = 0; idx < singleNum.size(); idx++) {
			if (num % singleNum[idx] != 0) return false;
		}
		return true;

		/* unordered_set can be used as well.
		* However, it is slower than the method above.
		unordered_set<int> ms;
		int numTmp = num;
		while (numTmp > 0) {
		if (numTmp % 10 == 0) return false;
		ms.insert(numTmp % 10);
		numTmp /= 10;
		}
		for (auto it = ms.begin(); it != ms.end(); it++) {
		if (num % *it != 0) return false;
		}
		return true;
		*/
	}

	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (unsigned int idx = left; idx < right + 1; idx++) {
			if (selfDividingNumbers(idx)) res.push_back(idx);
		}
		return res;
	}
};