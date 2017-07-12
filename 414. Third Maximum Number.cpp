/**
 * Given a non-empty array of integers, return the third maximum number in this array.
 * If it does not exist, return the maximum number. The time complexity must be in O(n).
 * Example 1:
 *  Input: [3, 2, 1]
 *  Output: 1
 *  Explanation: The third maximum is 1.
 * Example 2:
 *  Input: [1, 2]
 *  Output: 2
 *  Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 * Example 3:
 *  Input: [2, 2, 3, 1]
 *  Output: 1
 *  Explanation: Note that the third maximum here means the third maximum distinct number.
 *  Both numbers with value 2 are both considered as second maximum.
 *
 * Author: Adam Yu Wen
 * Date: July 12, 2017
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it;
        it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return nums[1];
        else return nums[nums.size() - 3];
    }
};
