/* Reverse bits of a given 32 bits unsigned integer.
 * Example:
 * Input: 43261596
 * Output: 964176192
 * Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
 *              return 964176192 represented in binary as 00111001011110000010100101000000.
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * https://leetcode.com/problems/reverse-bits/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 19, 2018
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string nStr = bitset<32>(n).to_string();
        reverse(nStr.begin(), nStr.end());
        return stoll(nStr, nullptr, 2);
    }
};
