/* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 * The order of output does not matter.
 * Example 1:
 * Input:
 * s: "cbaebabacd" p: "abc"
 * Output:
 * [0, 6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * Example 2:
 * Input:
 * s: "abab" p: "ab"
 * Output:
 * [0, 1, 2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 23, 2018
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        
        int sSize = s.size();
        int pSize = p.size();
        if (sSize < pSize) return res;
        
        unordered_map<char, int> sMp;
        unordered_map<char, int> pMp;
        for (int i = 0; i < pSize; i++) {
            sMp[s[i]]++;
            pMp[p[i]]++;
        }
        
        if (sMp == pMp) res.push_back(0);
        for (int i = 0; i < sSize - pSize; i++) {
            if (sMp[s[i]] == 1)
                sMp.erase(s[i]);
            else
                sMp[s[i]]--;
            sMp[s[i + pSize]]++;
            if (sMp == pMp)
                res.push_back(i + 1);
        }
        return res;
    }
};
