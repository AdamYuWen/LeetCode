/* Given a positive integer N, find and return the longest distance between two consecutive 1's
 * in the binary representation of N.
 * If there aren't two consecutive 1's, return 0.
 * Example 1:
 *   Input: 22
 *   Output: 2
 *   Explanation: 
 *   22 in binary is 0b10110.
 *   In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
 *   The first consecutive pair of 1's have distance 2.
 *   The second consecutive pair of 1's have distance 1.
 *   The answer is the largest of these two distances, which is 2.
 * Example 2:
 *   Input: 5
 *   Output: 2
 *   Explanation: 
 *   5 in binary is 0b101.
 * Example 3:
 *   Input: 6
 *   Output: 1
 *   Explanation: 
 *   6 in binary is 0b110.
 * Example 4:
 *   Input: 8
 *   Output: 0
 *   Explanation: 
 *   8 in binary is 0b1000.
 *   There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
 * Note:
 * 1 <= N <= 10^9
 * https://leetcode.com/problems/binary-gap/description/
 *
 * Author: Adam Yu Wen
 * Date: July 16, 2018
 */

// Method 1:
class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        string NStr = convertToBinary(N);
        int l = -1, r = 0;
        for (int i = 0; i < NStr.size(); i++) {
            if (l == -1 && NStr[i] == '1') {
                l = i;
                r = i;
            }
            else if (NStr[i] == '1') {
                r = i;
                res = max(res, r - l);
                l = r;
            }
        }
        return res;
    }
    
    string convertToBinary(int N) {
        string res = "";
        while (N != 0) {
            res = to_string(N % 2) + res;
            N /= 2;
        }
        return res;
    }
};


// Method 2:
// Reference: https://leetcode.com/problems/binary-gap/discuss/149835/C++JavaPython-Dividing-by-2
class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        // Because d value should not be more than 0 when the first 1 appears.
        // The initial value of d should be less than -31, which can be -32 or less.
        for (int d = -32; N; N /= 2, d++) {
            if (N % 2) {
                // If the first 1 appears, res == 0 and d < 0. So, res = 0.
                // If there are any more 1s, d counted the distance.
                res = max(res, d);
                // If the first 1 appears, d becomes to 0.
                // If there are any more 1s, reset the d to 0 after using it.
                d = 0;
            }
            cout << d << endl;
        }
        return res;
    }
};
