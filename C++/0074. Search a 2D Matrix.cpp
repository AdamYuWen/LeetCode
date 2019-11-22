/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * Example 1:
 * Input:
 * matrix = [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * Example 2:
 * Input:
 * matrix = [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * Author: Adam Yu Wen
 * Date: August 21, 2018
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowNum = matrix.size();
        if (!rowNum) return false;
        int colNum = matrix[0].size();
        if (!colNum) return false;
        
        // Find the row number
        int targetRow;
        for (int i = 0; i < rowNum; i++) {
            if (i == 0) {
                // The first row
                if (target < matrix[i][0]) {
                    return false;
                }
                if (rowNum == 1) {
                    targetRow = i;
                    break;
                }
            }
            else if (i == rowNum - 1) {
                // The last row
                if (target < matrix[i][0]) {
                    targetRow = i - 1;
                    break;
                }
                else {
                    targetRow = i;
                    break;
                }
            }
            else {
                if (target >= matrix[i - 1][0] && target < matrix[i][0]) {
                    targetRow = i - 1;
                    break;
                }
            }
        }
        
        // Find the column number
        for (int i = 0; i < colNum; i++) {
            if (target == matrix[targetRow][i]) {
                return true;
            }
            else if (target < matrix[targetRow][i]) {
                return false;
            }
        }
        return false;
    }
};
