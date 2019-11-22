/* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 * Example 1:
 * Input: 
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output: 
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 * Example 2:
 * Input: 
 * [
 *   [0,1,2,0],
 *   [3,4,5,2],
 *   [1,3,1,5]
 * ]
 * Output: 
 * [
 *   [0,0,0,0],
 *   [0,4,5,0],
 *   [0,3,1,0]
 * ]
 * Follow up:
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * Author: Adam Yu Wen
 * Date: June 29, 2018
 */

// Methode 1:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp = matrix;
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (tmp[i][j] == 0) {
                    for (int m = 0; m < rowNum; m++) {
                        matrix[m][j] = 0;
                    }
                    for (int n = 0; n < colNum; n++) {
                        matrix[i][n] = 0;
                    }
                }
            }
        }
    }
};


// Method 2:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        vector<int> zeroRows;
        vector<int> zeroCols;
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.push_back(i);
                    zeroCols.push_back(j);
                }
            }
        }
        for (int i = 0; i < zeroRows.size(); i++) {
            for (int j = 0; j < colNum; j++) {
                matrix[zeroRows[i]][j] = 0;
            }
        }
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < zeroCols.size(); j++) {
                matrix[i][zeroCols[j]] = 0;
            }
        }
    }
};
