/**
 * X is a good number if after rotating each digit individually by 180 degrees, we get a valid
 * number that is different from X.  Each digit must be rotated - we cannot choose to leave it
 * alone.
 * A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to
 * themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the
 * numbers do not rotate to any other number and become invalid.
 * Now given a positive number N, how many numbers X from 1 to N are good?
 * Example:
 * 	Input: 10
 * 	Output: 4
 * 	Explanation: 
 * 	There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
 * Note: N  will be in range [1, 10000].
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * Author: Adam Yu Wen
 * Date: April 23, 2018
 */
 
 // Method 1:
 // It takes 36 ms, which is slow.
 // Partially using math calculation and partially using string
class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for (int idx = 2; idx < N + 1; idx++) {
            if (validNum(idx)) cnt++;
        }
        return cnt;
    }
    
    bool validNum(int num) {
        int temp = num;
        string afterRotated;
        while (temp) {
            int remainder = temp % 10;
            if (remainder == 3 || remainder == 4 || remainder == 7) {
                return false;
            }
            else {
                int rotated;
                if (remainder == 0 || remainder == 1 || remainder == 8) rotated = remainder;
                else if (remainder == 2 || remainder == 5) rotated = remainder == 2 ? 5 : 2;
                else if (remainder == 6 || remainder == 9) rotated = remainder == 6 ? 9 : 6;
                afterRotated = to_string(rotated) + afterRotated;
            }
            temp /= 10;
        }
        if (num == stoi(afterRotated)) return false;
        return true;
    }
};

// Method 2:
// It takes 27 ms, which is slow.
// Using string
class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for (int idx = 2; idx < N + 1; idx++) {
            if (validNum(idx)) cnt++;
        }
        return cnt;
    }
    
    bool validNum(int num) {
        string strNum = to_string(num);
        string rotatedStrNum = "";
        int strNumSize = strNum.size();
        for (int idx = 0; idx < strNumSize; idx++) {
            if (strNum[idx] == '3' || strNum[idx] == '4' || strNum[idx] == '7') {
                return false;
            }
            else {
                string roatatedSingleNum = "";
                if (strNum[idx] == '2') roatatedSingleNum = "5";
                else if (strNum[idx] == '5') roatatedSingleNum = "2";
                else if (strNum[idx] == '6') roatatedSingleNum = "9";
                else if (strNum[idx] == '9') roatatedSingleNum = "6";
                else roatatedSingleNum = strNum[idx];
                rotatedStrNum += roatatedSingleNum;
            }
        }
        if (num == stoi(rotatedStrNum)) return false;
        return true;
    }
};