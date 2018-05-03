/**
 * Given a non-negative integer c, your task is to decide whether
 * there're two integers a and b such that a2 + b2 = c.
 * Example 1:
 * 	Input: 5
 * 	Output: True
 * 	Explanation: 1 * 1 + 2 * 2 = 5
 * Example 2:
 * 	Input: 3
 * 	Output: False
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * Author: Adam Yu Wen
 * Date: May 3, 2018
 */
 
// Method 1:
// It takes 163 ms, which is slow.
class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int, int> mp;
        getAllSquares(c, mp);
        for (auto num : mp) {
            if (mp.count(c - num.first)) {
                return true;
            }
        }
        return false;
    }
    
    void getAllSquares(int c, unordered_map<int, int> &mp) {
        mp[0]++;
        long sum = 1;
        long odd = 1;
        while (sum <= c) {
            mp[sum]++;
            odd += 2;
            sum += odd;
        }
    }
};


// Method 2:
// It takes 4 ms. It comes from LeetCode submissions.
class Solution {
public:
    bool judgeSquareSum(int c) {
        int b = 0, e = (int)sqrt(c);
        while(b <= e) {
            long sum = b * b + e * e;
            if (sum == c) {
                return true;
            } else if (sum >= c) {
                e--;
            } else {
                b++;
            }
        }
        return false;
    }
};