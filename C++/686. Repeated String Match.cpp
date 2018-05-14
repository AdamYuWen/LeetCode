/*
 * Given two strings A and B, find the minimum number of times A has to be
 * repeated such that B is a substring of it. If no such solution, return -1.
 * For example, with A = "abcd" and B = "cdabcdab".
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a
 * substring of it; and B is not a substring of A repeated two times ("abcdabcd").
 * Note:
 * The length of A and B will be between 1 and 10000.
 * https://leetcode.com/problems/repeated-string-match/description/
 *
 * Author: Adam Yu Wen
 * Date: December 19, 2017
 */

int repeatedStringMatch(string A, string B) {
	int res = 1;
	string originalA = A;
	while (A.size() < B.size()) {
		A += originalA;
		res++;
	}

	size_t found = A.find(B);
	if (found != string::npos) {
		return res;
	}
	else {
		// Add one more time.
		// If still not finding it,
		// there is no.
		A += originalA;
		res++;
		found = A.find(B);
		if (found != string::npos) {
			return res;
		}
		else return -1;
	}
}