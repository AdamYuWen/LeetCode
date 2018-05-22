/* Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's permutations
 * is the substring of the second string.
 * Example 1:
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * Example 2:
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * Note:
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * https://leetcode.com/problems/permutation-in-string/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 22, 2018
 */

// Method 1:
// It takes extremely long time, which is 1571 ms.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();
        if (s1Size > s2Size) return false;
        
        unordered_map<char, int> mp;
        for (int i = 0; i < s1Size; i++) {
            mp[s1[i]]++;
        }
        
        unordered_map<char, int> mpTmp;
        mpTmp = mp;
        for (int i = 0; i < s2Size - s1Size + 1; i++) {
            for (int j = i; j < i + s1Size; j++) {
                if (mpTmp[s2[j]]) {
                    mpTmp[s2[j]]--;
                } else {
                    mpTmp = mp;
                    break;
                }
                if (j == i + s1Size - 1)
                    return true;
            }
        }
        return false;
    }
};


// Method 2:
// It is faster, which takes 21 ms.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();
        if (s1Size > s2Size) return false;

        unordered_map<char, int> s1Mp;
        unordered_map<char, int> s2Mp;
        for (int i = 0; i < s1Size; i++) {
            s1Mp[s1[i]]++;
            s2Mp[s2[i]]++;
        }
        if (s1Mp == s2Mp) return true;
        for (int i = 0; i < s2Size - s1Size; i++) {
            if (s2Mp[s2[i]] == 1)
	        // The item need to be removed.
	        // If we only do s2Mp[s2[i]]--,
	        // the key is still in the map
                s2Mp.erase(s2[i]);
            else
                s2Mp[s2[i]]--;
            s2Mp[s2[s1Size + i]]++;
            if (s1Mp == s2Mp) return true;
        }
        return false;
    }
};
