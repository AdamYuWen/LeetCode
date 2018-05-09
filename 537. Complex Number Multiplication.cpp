/* Given two strings representing two complex numbers.
 * You need to return a string representing their multiplication. Note i2 = -1
 * according to the definition.
 * Example 1:
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 * Example 2:
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 * Note:
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be also
 * in this form.
 * https://leetcode.com/problems/complex-number-multiplication/description/
 *
 * Author: Adam Yu Wen
 * Date: May 8, 2018
 */

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int plusInA = a.find("+");
        int plusInB = b.find("+");
        
        int intInA = stoi(a.substr(0, plusInA));
        int intInB = stoi(b.substr(0, plusInB));
        int complexInA = stoi(a.substr(plusInA + 1, a.size() - 1));
        int complexInB = stoi(b.substr(plusInB + 1, a.size() - 1));
        
        int resInt = intInA * intInB - complexInA * complexInB;
        int resComplex = intInA * complexInB + intInB * complexInA;
        
        return to_string(resInt) + "+" + to_string(resComplex) + "i";
    }
};
