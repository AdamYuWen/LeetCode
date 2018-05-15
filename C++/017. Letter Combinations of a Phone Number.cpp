/* Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is
 * given below. Note that 1 does not map to any letters.
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could
 * be in any order you want.
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * Author: Adam Yu Wen
 * Date: May 14, 2018
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int digitsSize = digits.size();
        if (digitsSize == 0) return res;
        if (digitsSize == 1) {
            res = numToLetter(digits[0]);
        }
        else {
            vector<string> pre = letterCombinations(digits.substr(0, digitsSize - 1));
            int preSize = pre.size();
            for (int i = 0; i < preSize; i++) {
                vector<string> appendStr = numToLetter(digits[digitsSize - 1]);
                int appendStrSize = appendStr.size();
                for (int j = 0; j < appendStrSize; j++) {
                    res.push_back(pre[i]);
                    res.back() = res.back() + appendStr[j];
                }
            }
        }
        return res;
    }

    vector<string> numToLetter(char num) {
        vector<string> res;
        switch (num) {
        case '2': {
            res.push_back("a");
            res.push_back("b");
            res.push_back("c");
            break;
            }
        case '3': {
            res.push_back("d");
            res.push_back("e");
            res.push_back("f");
            break;
        }
        case '4': {
            res.push_back("g");
            res.push_back("h");
            res.push_back("i");
            break;
        }
        case '5': {
            res.push_back("j");
            res.push_back("k");
            res.push_back("l");
            break;
        }
        case '6': {
            res.push_back("m");
            res.push_back("n");
            res.push_back("o");
            break;
        }
        case '7': {
            res.push_back("p");
            res.push_back("q");
            res.push_back("r");
            res.push_back("s");
            break;
        }
        case '8': {
            res.push_back("t");
            res.push_back("u");
            res.push_back("v");
            break;
        }
        case '9': {
            res.push_back("w");
            res.push_back("x");
            res.push_back("y");
            res.push_back("z");
            break;
        }
        }
        return res;
    }
};
