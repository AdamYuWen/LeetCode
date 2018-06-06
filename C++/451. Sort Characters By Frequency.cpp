/* Given a string, sort it in decreasing order based on the frequency of characters.
 * Example 1:
 * Input:
 * "tree"
 * Output:
 * "eert"
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * Example 2:
 * Input:
 * "cccaaa"
 * Output:
 * "cccaaa"
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * Example 3:
 * Input:
 * "Aabb"
 * Output:
 * "bbAa"
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 * Reference: http://www.cnblogs.com/grandyang/p/6231504.html
 *
 * Author: Adam Yu Wen
 * Date: June 6, 2018
 */

// Method 1:
// It is slow, which takes 294 ms.
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
	// unordered_map cannot be sorted
	// Instead sorting unordered_map, sorting string s.
	// Using [&], otherwise mp cannot be used.
        sort(s.begin(), s.end(), [&](char &a, const char &b) {
            return mp[a] > mp[b] || (mp[a] == mp[b] && a < b);
            });
        return s;
    }
};


// Method 2:
// It is from LeetCode Solutions, which only takes 12 ms.
class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(128);
        for(auto c: s) cnt[c]++;
        vector<pair<int, int>> arr;
        for(int i = 0; i < 128; i++) {
            if(cnt[i])
                arr.push_back({cnt[i], i});
        }
        sort(arr.begin(), arr.end(), [](const auto& lhs, const auto& rhs) { return lhs.first > rhs.first; });
        string ans;
        for(auto& pr: arr) {
            ans.append(pr.first, pr.second);
        }
        return ans;
    }
};
