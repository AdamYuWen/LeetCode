/* A string S of lowercase letters is given. We want to partition this string into as many parts as
 * possible so that each letter appears in at most one part, and return a list of integers
 * representing the size of these parts.
 * Example 1:
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 * Note:
 * S will have length in range [1, 500].
 * S will consist of lowercase letters ('a' to 'z') only.
 * https://leetcode.com/problems/partition-labels/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 24, 2018
 */

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < S.size(); i++) {
            mp[S[i]].push_back(i);
        }
        int start = mp[S[0]][0];
        int end = mp[S[0]].back();
        // If the end reach to the string end
        if (end == S.size() - 1)
            res.push_back(end - start + 1);
        
        while (end != S.size() - 1) {
            for (int i = start; i < end; i++) {
                if (mp[S[i]].back() > end) {
                    end = mp[S[i]].back();
                }
            }
            res.push_back(end - start + 1);
            // Checking end for assigning new start and end
            if (end != S.size() - 1) {
                start = mp[S[end + 1]][0];
                end = mp[S[end + 1]].back();
                // If the end reach to the string end
                if (end == S.size() - 1)
                    res.push_back(end - start + 1);
            }
        }
        return res;
    }
};
