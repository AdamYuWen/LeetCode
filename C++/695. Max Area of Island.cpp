/* Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected
 * 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 * Example 1:
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * Note: The length of each dimension in the given grid does not exceed 50.
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * Author: Adam Yu Wen
 * Date: August 17, 2018
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rowNum = grid.size();
        if (!rowNum) return 0;
        int colNum = grid[0].size();
        
        vector<vector<bool>> visited(rowNum, vector<bool>(colNum, false));
        int res = 0;
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                res = max(res, countArea(grid, rowNum, colNum, visited, i, j));
            }
        }
        return res;
    }
    
    int countArea(vector<vector<int>> &grid, int rowNum, int colNum, vector<vector<bool>> &visited, int row, int col) {
        if (row < 0 || row >= rowNum || col < 0 || col >= colNum || visited[row][col] || !grid[row][col]) {
            return 0;
        }
        else {
            visited[row][col] = true;
            return 1 +
                countArea(grid, rowNum, colNum, visited, row - 1, col) +
                countArea(grid, rowNum, colNum, visited, row + 1, col) +
                countArea(grid, rowNum, colNum, visited, row, col - 1) +
                countArea(grid, rowNum, colNum, visited, row, col + 1);
        }
    }
};
