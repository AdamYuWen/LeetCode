/* Given a non-empty array of integers, return the k most frequent elements.
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * Note: 
 * You may assume k is always valid, 1 <= k <= number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 * Reference: http://www.cnblogs.com/grandyang/p/5454125.html
 *
 * Author: Adam Yu Wen
 * Date: June 7, 2018
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> q;
        for (auto c : nums) mp[c]++;
        for (auto it : mp) q.push({it.second, it.first});
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
