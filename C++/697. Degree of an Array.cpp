/* Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * Example 1:
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * Example 2:
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * Author: Adam Yu Wen
 * Date: May 16, 2018
 */

// Method 1:
// The map only store the number of times
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = INT_MAX;
        // key == num, value == the number of times
        unordered_map<int, int> mp;
        int maxCnt = INT_MIN;
        
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++) {
            mp[nums[i]]++;
            maxCnt = max(maxCnt, mp[nums[i]]);
        }
        
        for (auto it : mp) {
            if (it.second == maxCnt) {
                int start = 0, end = 0;
		// find the forst occurrence
                for (int i = 0; i < numsSize; i++) {
                    if (nums[i] == it.first) {
                        start = i;
                        break;
                    }
                }
		// find the last occurrence
                for (int i = numsSize - 1; i > -1; i--) {
                    if (nums[i] == it.first) {
                        end = i;
                        break;
                    }
                }
                res = min(res, end - start + 1);
            }
        }
        
        return res;
    }
};


// Method 2:
// The map stores the number of times, start idx, and end idx
// It is a little faster.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = INT_MAX;
        // key == num
        // value1 == the number of times
        // value2 == the start index
        // value3 == the end indx
        unordered_map<int, vector<int>> mp;
        int maxCnt = INT_MIN;
        
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++) {
            if (mp.count(nums[i])) {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else {
                mp[nums[i]].push_back(1);
                mp[nums[i]].push_back(i);
                mp[nums[i]].push_back(i);
            }
            
            maxCnt = max(maxCnt, mp[nums[i]][0]);
        }
        
        for (auto it : mp) {
            if (it.second[0] == maxCnt) {
                res = min(res, it.second[2] - it.second[1] + 1);
            }
        }
        
        return res;
    }
};
