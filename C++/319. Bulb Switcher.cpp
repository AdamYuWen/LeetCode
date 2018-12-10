/* There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off
 * every second bulb. On the third round, you toggle every third bulb (turning on if it's off or
 * turning off if it's on). For the i-th round, you toggle every i bulb. For the n-th round, you
 * only toggle the last bulb. Find how many bulbs are on after n rounds.
 * 
 * Example:
 * Input: 3
 * Output: 1 
 * Explanation: 
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off]. 
 * So you should return 1, because there is only one bulb is on.
 * https://leetcode.com/problems/bulb-switcher/
 * 
 * Author: Adam Yu Wen
 * Date: December 10, 2018
 * Reference: http://www.cnblogs.com/grandyang/p/5100098.html
 */

// Method 1:
// Runtime Error for 99999999, because there are many FOR loops.
class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0) return 0;
        
        int res = 0;
        bool resArr[n];
        
        // Initialize an array with all false
        for (int idx = 0; idx < n; idx++) {
            resArr[idx] = false;
        }
        
        // Change lights
        for (int roundIdx = 1; roundIdx < n + 1; roundIdx++) {
            for (int elemIdx = roundIdx - 1; elemIdx < n; elemIdx += roundIdx) {
                resArr[elemIdx] = !resArr[elemIdx];
            }
        }
        
        // Count the result
        for (int idx = 0; idx < n; idx++) {
            if (resArr[idx] == true) {
                res++;
            }
        }
        
        return res;
    }
};


//Method 2:
class Solution {
public:
    int bulbSwitch(int n) {
        int res = 1;
        while (res * res <= n) {
            res++;
        }
        return res - 1;
    }
};
