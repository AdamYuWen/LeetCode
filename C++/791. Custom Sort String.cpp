/* S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
 * S was sorted in some custom order previously. We want to permute the characters of T so that they match the
 * order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the
 * returned string.
 * Return any permutation of T (as a string) that satisfies this property.
 * Example :
 * Input: 
 * S = "cba"
 * T = "abcd"
 * Output: "cbad"
 * Explanation: 
 * "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
 * Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
 * Note:
 * S has length at most 26, and no character is repeated in S.
 * T has length at most 200.
 * S and T consist of lowercase letters only.
 * https://leetcode.com/problems/custom-sort-string/description/
 *
 * Author: Adam Yu Wen
 * Date: July 12, 2018
 */

class Solution {
public:
    string customSortString(string S, string T) {
        string res = "";
        unordered_map<char, int> mp;
        for (auto c : T) {
            mp[c]++;
        }
        for (auto c : S) {
            if (mp.count(c) > 0) {
                string add(mp[c], c);
                res += add;
                mp.erase(c);
            }
        }
        for (auto m : mp) {
            string add(m.second, m.first);
            res += add;
        }
        return res;
    }
};
