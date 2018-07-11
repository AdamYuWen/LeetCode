/* Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 * Note:
 * The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * You could assume no leading zero bit in the integer's binary representation.
 * Example 1:
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 * Example 2:
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 * https://leetcode.com/problems/number-complement/description/
 * 
 * Author: Adam Yu Wen
 * Date: July 11, 2018
 */

class Solution {
public:
    int findComplement(int num) {
        string binaryStr = convertToBinary(num);
        string binaryFlipStr = "";
        for (int i = 0; i < binaryStr.size(); i++) {
            if (binaryStr[i] == '1') {
                binaryFlipStr += "0";
            }
            else {
                binaryFlipStr += "1";
            }
        }
        return convertToInt(binaryFlipStr);
    }
    
    string convertToBinary(int n) {
        string res = "";
        vector<int> binaryNum;
        
        while (n > 0) {
            binaryNum.push_back(n % 2);
            n /= 2;
        }
        
        for (int j = binaryNum.size() - 1; j >= 0; j--) {
            res += to_string(binaryNum[j]);
        }
        
        return res;
    }
    
    int convertToInt(string str) {
        int res = 0;
        
        int strSize = str.size();
        for (int i = 0; i < strSize; i++) {
            res += pow(2, strSize - i - 1) * (str[i] - '0');
        }
        
        return res;
    }
};
