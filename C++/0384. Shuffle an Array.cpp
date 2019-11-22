/* Shuffle a set of numbers without duplicates.
 * Example:
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 * https://leetcode.com/problems/shuffle-an-array/description/
 * 
 * Author: Adam Yu Wen
 * Date: July 13, 2018
 */

class Solution {
public:
    Solution(vector<int> nums) {
        privateNums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
       return privateNums; 
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;
        int numsSize = privateNums.size();
        
        vector<int> index;  // index are numbers from 0 to nums.size() - 1
        for (int i = 0; i < numsSize; i++) {
            index.push_back(i);
        }
        
        while (index.size()) {
            // select any number from index
            int randIdx = int(rand() % index.size());
            // push the number from nums with the selected index into res
            res.push_back(privateNums[index[randIdx]]);
            // remove the used index from index
            index.erase(index.begin() + randIdx);
        }
        
        return res;
    }
    
private:
    vector<int> privateNums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
