/* Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible strings
 * we could create.
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 * Input: S = "12345"
 * Output: ["12345"]
 * Note:
 * S will be a string with length at most 12.
 * S will consist only of letters or digits.
 * https://leetcode.com/problems/letter-case-permutation/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 23, 2018
 */

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        int start = 0;
        letterCasePermutationHelper(S, start, res);
        res.push_back(S);
        return res;
    }
    
    void letterCasePermutationHelper(string S, int start, vector<string> &res) {
        int SSize = S.size();
        for (int i = start; i < SSize; i++) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                string STmp = S;
                STmp[i] -= 32;
                res.push_back(STmp);
                letterCasePermutationHelper(STmp, i + 1, res);
            }
            else if (S[i] >= 'A' && S[i] <= 'Z') {
                string STmp = S;
                STmp[i] += 32;
                res.push_back(STmp);
                letterCasePermutationHelper(STmp, i + 1, res);
            }
        }
    }
};
