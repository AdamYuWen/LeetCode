/**
 * Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
 * You may assume the array's length is at most 10,000.
 * Example:
 * Input: [1,2,3]
 * Output: 2
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one element):
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 * Author: Adam Yu Wen
 * Date: July 07, 2017
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // The midPoint should be the median
        // It is not the mean (average)
        // For example, [1, 0, 0, 8, 6]
        sort(nums.begin(), nums.end());
        int midPoint = nums.at(int(nums.size() / 2));
        int res = 0;
        for(int idx = 0; idx < nums.size(); idx++) {
            res += abs(nums.at(idx) - midPoint);
        }
        return res;
    }
};
