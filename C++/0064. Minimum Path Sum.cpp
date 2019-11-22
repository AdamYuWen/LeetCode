/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom
 * right which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 * Example:
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1-3-1-1-1 minimizes the sum.
 * https://leetcode.com/problems/minimum-path-sum/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4353255.html
 *
 * Author: Adam Yu Wen
 * Date: June 7, 2018
 */

// Method 1:
// It is Time Limited Exceeded, but 60/61 test cases passed.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int sum = 0;
        minPathSumHelper(grid.size() - 1, grid[0].size() - 1, grid, sum, res);
        return res;
    }
    
    void minPathSumHelper(int row, int col, vector<vector<int>> &grid, int &sum, int &res) {
        if (sum > res) return;
        
        if (row == 0 && col == 0) {
            res = min(res, sum + grid[row][col]);
        }
        sum += grid[row][col];
        if (row) {
            minPathSumHelper(row - 1, col, grid, sum, res);
        }
        if (col) {
            minPathSumHelper(row, col - 1, grid, sum, res);
        }
        sum -= grid[row][col];
    }
};


// Method 2:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowNum = grid.size();
        int colNum = grid[0].size();
        int dp[rowNum][colNum];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rowNum; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int i = 1; i < colNum; i++) dp[0][i] = grid[0][i] + dp[0][i - 1];
        for (int i = 1; i < rowNum; i++) {
            for (int j = 1; j < colNum; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[rowNum - 1][colNum - 1];
    }
};