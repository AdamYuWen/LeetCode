/* Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * https://leetcode.com/problems/add-binary/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4084971.html
 * 
 * Author: Adam Yu Wen
 * Date: May 18, 2018
 */

// Method 1:
// The code is long.
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";

        int aSize = a.size();
        int bSize = b.size();
        int smallSize = min(aSize, bSize);

        bool carry = false;
        for (int i = 1; i < smallSize + 1; i++) {
            string resTmp;
            if (a[aSize - i] == '0' && b[bSize - i] == '0' && carry == false) {
                resTmp = "0";
            }
            else if ((a[aSize - i] == '0' && b[bSize - i] == '0' && carry == true) ||
                (a[aSize - i] == '0' && b[bSize - i] == '1' && carry == false) ||
                (a[aSize - i] == '1' && b[bSize - i] == '0' && carry == false)) {
                resTmp = "1";
                carry = false;
            }
            else if (a[aSize - i] == '1' && b[bSize - i] == '1' && carry == false) {
                resTmp = "0";
                carry = true;
            }
            else if ((a[aSize - i] == '0' && b[bSize - i] == '1' && carry == true) ||
                (a[aSize - i] == '1' && b[bSize - i] == '0' && carry == true)) {
                resTmp = "0";
                carry = true;
            }
            else { // (a[aSize - i] == '1' && b[bSize - i] == '1' && carry == true)
                resTmp = "1";
                carry = true;
            }
            res = resTmp + res;
        }

        if (carry) {
            string resTmp;
            if (aSize == bSize) {
                resTmp = "1";
            }
            else if (aSize > bSize) {
                resTmp = addBinary(a.substr(0, aSize - bSize), "1");
            }
            else { // aSize < bSize
                resTmp = addBinary(b.substr(0, bSize - aSize), "1");
            }
            res = resTmp + res;
            return res;
        }

        if (aSize > bSize) {
            return a.substr(0, aSize - bSize) + res;
        }
        else { // aSize <= bSize
            return b.substr(0, bSize - aSize) + res;
        }
    }
};


// Method 2:
// The code is from the reference and it is a more simpler solution.
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};
