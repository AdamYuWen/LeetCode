/**
 * Given a positive integer num, write a function which returns True
 * if num is a perfect square else False.
 * Note: Do not use any built-in library function such as sqrt.
 * Example 1:
 * 	Input: 16
 * 	Returns: True
 * Example 2:
 * 	Input: 14
 * 	Returns: False
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * Author: Adam Yu Wen
 * Date: May 3, 2018
 */
 
class Solution {
public:
    bool isPerfectSquare(int num) {
        long odd = 1;
        long sumOdd = 1;
        while (sumOdd <= num) {
            if (sumOdd == num) return true;
            odd += 2;
            sumOdd += odd;
        }
        return false;
    }
};