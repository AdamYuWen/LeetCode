/**
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7]
 * is rotated to [5,6,7,1,2,3,4].
 * Note:
 * Try to come up as many solutions as you can, there are at
 * least 3 different ways to solve this problem.
 * Related problem: Reverse Words in a String II
 *
 * Author: Adam Yu Wen
 * Date: July 11, 2017
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // If k > nums.size()
        // reduce the number of steps
        int reduceStep = k % nums.size();
        for(int idx = 0; idx < reduceStep; idx++) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
};
