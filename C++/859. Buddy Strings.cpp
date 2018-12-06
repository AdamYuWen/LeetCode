/* Given two strings A and B of lowercase letters, return true if and only if we can swap
 * two letters in A so that the result equals B.
 * Example 1:
 * Input: A = "ab", B = "ba"
 * Output: true
 * Example 2:
 * Input: A = "ab", B = "ab"
 * Output: false
 * Example 3:
 * Input: A = "aa", B = "aa"
 * Output: true
 * Example 4:
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * Example 5:
 * Input: A = "", B = "aa"
 * Output: false
 * Note:
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A and B consist only of lowercase letters.
 * https://leetcode.com/problems/buddy-strings/description/
 *
 * Author: Adam Yu Wen
 * Date: June 25, 2018
 */

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A == "" && B == "") {
            return false;
        }
        if (A == B) {
            sort(A.begin(), A.end());
            for (int i = 0; i < A.size() - 1; i++) {
                if (A[i] == A[i + 1]) {
                    return true;
                }
            }
        }
        int ASize = A.size();
        int BSize = B.size();
        if (ASize != BSize) {
            return false;
        }
        int prev = -1, curr = -1, cnt = 0;
        for (int i = 0; i < ASize; i++) {
            if (A[i] != B[i]) {
                cnt++;
                if (cnt > 2) {
                    return false;
                }
                prev = curr;
                curr = i;
            }
            
        }
        return (cnt == 2 && A[prev] == B[curr] && A[curr] == B[prev]);
    }
};
