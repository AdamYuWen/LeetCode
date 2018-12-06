/* Given an array A of non-negative integers, return an array consisting of all the even elements of A,
 * followed by all the odd elements of A.
 * You may return any answer array that satisfies this condition.
 * 
 * Example 1:
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * Note:
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * https://leetcode.com/problems/sort-array-by-parity/
 * 
 * Author: Adam Yu Wen
 * Date: December 6, 2018
 */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even;
        vector<int> odd;
        for (int idx = 0; idx < A.size(); idx++) {
            if (A[idx] % 2 == 0) {
                even.push_back(A[idx]);
            } else {
                odd.push_back(A[idx]);
            }
        }
        for (int idx = 0; idx < odd.size(); idx++) {
            even.push_back(odd[idx]);
        }
        return even;
    }
};
