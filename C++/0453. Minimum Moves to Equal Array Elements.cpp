/**
 * Given a non-empty integer array of size n, find the minimum number of
 * moves required to make all array elements equal, where a move is incrementing
 * n - 1 elements by 1.
 * Example:
 * Input: [1,2,3]
 * Output: 3
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 *
 * Author: Adam Yu Wen
 * Date: July 07, 2017
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        // Incrementing n-1 elements by 1 is the same as
        // decrementing the largest by 1
        // So, the question becomes to decrease all elements
        // to the same as the smallest one
        int minEle = *min_element(nums.begin(), nums.end());
        for(int idx = 0; idx < nums.size(); idx++) {
            res += (nums.at(idx) - minEle);
        }
        return res;
    }
};
