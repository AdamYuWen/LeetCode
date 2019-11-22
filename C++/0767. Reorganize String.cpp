/* Given a string S, check if the letters can be rearranged so that two characters that
 * are adjacent to each other are not the same.
 * If possible, output any possible result.  If not possible, return the empty string.
 * Example 1:
 * Input: S = "aab"
 * Output: "aba"
 * Example 2:
 * Input: S = "aaab"
 * Output: ""
 * Note:
 * S will consist of lowercase letters and have length in range [1, 500].
 *
 * Author: Adam Yu Wen
 * Date: July 10, 2018
 */

// Its runtime beats 100.00% of cpp submissions.
class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        
        unordered_map<char, int> mp;
        for (auto c : S) {
            mp[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto m : mp) {
            if (m.second > (S.size() + 1) / 2) {
                return "";
            }
            pq.push({m.second, m.first});
        }
        
        while (pq.size() > 1) {
            auto t1 = pq.top(); pq.pop();
            auto t2 = pq.top(); pq.pop();
            res += t1.second;
            res += t2.second;
            if (--t1.first > 0) pq.push(t1);
            if (--t2.first > 0) pq.push(t2);
        }
        
        if (pq.size() == 1) {
            res += pq.top().second;
        }
        return res;
    }
};
