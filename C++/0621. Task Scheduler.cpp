/* Given a char array representing tasks CPU need to do. It contains capital letters A to Z where
 * different letters represent different tasks.Tasks could be done without original order. Each
 * task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 * However, there is a non-negative cooling interval n that means between two same tasks, there must
 * be at least n intervals that CPU are doing different tasks or just be idle.
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 * Example 1:
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * Note:
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * Author: Adam Yu Wen
 * Date: July 9, 2018
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto m : mp) {
            pq.push({m.second, m.first});
        }

        // largest is the largest number that a char appears
        // cnt is the number of char that appear the same amount of times as the largest
        int largest = pq.top().first;
        int cnt = 0;
        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            if (largest == t.first) {
                cnt++;
            }
            else {
                break;
            }
        }

        // Sometims, n is very small, eg n == 0, the calculated number may smaller than the tasksSize
        int tasksSize = tasks.size();
        return max(tasksSize, (largest - 1) * (n + 1) + cnt);
    }
};
