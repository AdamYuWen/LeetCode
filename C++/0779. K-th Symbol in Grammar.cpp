/* On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence
 * of 0 with 01, and each occurrence of 1 with 10.
 * 
 * Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).
 * 
 * Examples:
 * Input: N = 1, K = 1
 * Output: 0
 * 
 * Input: N = 2, K = 1
 * Output: 0
 * 
 * Input: N = 2, K = 2
 * Output: 1
 * 
 * Input: N = 4, K = 5
 * Output: 1
 * 
 * Explanation:
 * row 1: 0
 * row 2: 01
 * row 3: 0110
 * row 4: 01101001
 * Note:
 * 
 * N will be an integer in the range [1, 30].
 * K will be an integer in the range [1, 2^(N-1)].
 * https://leetcode.com/problems/k-th-symbol-in-grammar/
 *
 * Author: Adam Yu Wen
 * December 7, 2018
 */

// Method 1:
// It is Memory Limit Exceeded.
class Solution {
public:
    int kthGrammar(int N, int K) {
        string prevRow = "0";
        string currRow;
        for (int idx = 0; idx < N; idx++) {
            if (idx == 0) {
                currRow = prevRow;
            } else {
                prevRow = currRow;
                currRow = convertToCurr(prevRow);
            }
        }
        return currRow[K - 1] - '0';
    }
    
    string convertToCurr(string prevRow) {
        string res = "";
        for (int idx = 0; idx < prevRow.size(); idx++) {
            if (prevRow[idx] == '0') {
                res += "01";
            } else {
                res += "10";
            }
        }
        return res;
    }
};

// Method 2:
/* Index tree
 * N = 1:        1
 * N = 2:    1       2
 * N = 3:  1   2   3   4
 * N = 4: 1 2 3 4 5 6 7 8
 */
class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            // If it is the first row, return 0
            return 0;
        } else if (kthGrammar(N - 1, (K + 1) / 2) == 0) {
            // If the input is N = 4 and K = 5,
            // find N = 3 and K = 3.
            return K % 2 == 0 ? 1 : 0;
        } else {
            return K % 2 == 0 ? 0 : 1;
        }
    }
};
