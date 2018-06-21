/* Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * https://leetcode.com/problems/reverse-integer/
 *
 * Author: Adam Yu Wen
 * Date: October 31, 2016
 */

class Solution {
public:
    int reverse(long long x) {
        // the type of parameter is changed to long long
        // if x is larger the scope of int, return 0
        // for example, if x is 2147483678, it returns 0
        if (x > INT_MAX) return 0;
        if (x >= 0) {
            if (x < 10) return x;
            else {
                long long res = 0;
                while (x >= 10) {
                    res = res * 10 + (x % 10);
                    x /= 10;
                }
                res = res * 10 + x;
                if (res > INT_MAX) return 0;
                else return int(res);
            }
        }
        else {
            return -reverse(-x);
        }
    }
};
