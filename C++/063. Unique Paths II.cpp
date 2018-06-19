/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * Note: m and n will be at most 100.
 * Example 1:
 * Input:
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * https://leetcode.com/problems/unique-paths-ii/description/
 * 
 * Author: Adam Yu Wen
 * Date: June 19, 2018
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int obstaclePathNum = 1;
        int numRow = obstacleGrid.size();
        int numCol = obstacleGrid[0].size();
        vector<vector<int>> dp(numRow, vector<int>(numCol, 0));
        dp[0][0] = 1;
        for (int row = 0; row < numRow; row++) {
            for (int col = 0; col < numCol; col++) {
                if (obstacleGrid[row][col]) {
                    dp[row][col] = 0;
                    continue;
                }
                if (row > 0) {
                    dp[row][col] += dp[row - 1][col];
                }
                if (col > 0) {
                    dp[row][col] += dp[row][col - 1];
                }
            }
        }
        return dp[numRow - 1][numCol - 1];
    }
};
