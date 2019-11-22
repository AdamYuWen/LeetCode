/* Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.
 * Example 1:
 * Input: "leetcodeisacommunityforcoders"
 * Output: "ltcdscmmntyfrcdrs"
 * Example 2:
 * Input: "aeiou"
 * Output: ""
 * Note:
 * S consists of lowercase English letters only.
 * 1 <= S.length <= 1000* https://leetcode.com/problems/remove-vowels-from-a-string//
 *
 * Author: Adam Yu Wen
 * Date: November 22, 2019
 */

Class Solution {
public:
    string removeVowels(string S) {
        string ret = "";
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (auto c : S) {
            if (vowels.find(c) == vowels.end()) {
                ret += c;
            }
        }
        return ret;
    }
};
