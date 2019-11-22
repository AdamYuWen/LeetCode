/**
 * A zero-indexed array A of length N contains all integers from 0 to N-1. Find and
 * return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }
 * subjected to the rule below.
 * Suppose the first element in S starts with the selection of element A[i] of index = i,
 * the next element in S should be A[A[i]], and then A[A[A[i]]]... By that analogy, we stop
 * adding right before a duplicate element occurs in S.
 * Example 1:
 * Input: A = [5,4,0,3,1,6,2]
 * Output: 4
 * Explanation: 
 * A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
 * One of the longest S[K]:
 * S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 * Note:
 * N is an integer within the range [1, 20,000].
 * The elements of A are all distinct.
 * Each element of A is an integer within the range [0, N-1].
 * https://leetcode.com/problems/array-nesting/description/
 *
 * Author: Adam Yu Wen
 * Date: May 4, 2018
 */

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        // The elements of A are alll distinct
        // ==> If it starts at a point, it must be ending at the piont also.
        int numsSize = nums.size();
        int res = 0;
        for (int idx = 0; idx < numsSize; idx++) {
            // If the value is -1, it means that the cycle is counted already.
            if (nums[idx] == -1) continue;
            else {
                // A number itself is a cycle.
                if (nums[idx] == idx) res = res ? res : 1;
                else {
                    int startIdx = idx;
                    int nextIdx = nums[idx];
                    int resTemp = 0;
                    // If it comes to -1, it means the cycle is ended.
                    while (nums[nextIdx] != -1) {
                        int currIdx = nextIdx;
                        nextIdx = nums[nextIdx];
                        // Change the value to -1 for avoiding multiple counting.
                        nums[currIdx] = -1;
                        resTemp++;
                    }
                    res = max(res, resTemp);
                }
            }
        }
        return res;
    }
};
