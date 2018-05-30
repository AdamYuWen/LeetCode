/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * Note: m and n will be at most 100.
 * Example 1:
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * Example 2:
 * Input: m = 7, n = 3
 * Output: 28
 * https://leetcode.com/problems/unique-paths/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 30, 2018
 */

// Method 1:
// Math method.
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        long long res = 1;
        int small = min(m, n);
        for (int i = 1; i < small; i++) {
            res = res * (m + n - 1 - i) / i;
        }
        return int(res);
    }
};


// Method 2:
// Dynamic programming method.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m, vector<int>(n, 0));
        res[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    res[i][j] += res[i - 1][j];
                if (j > 0)
                    res[i][j] += res[i][j - 1];
            }
        }
        return res[m - 1][n - 1];
    }
};
