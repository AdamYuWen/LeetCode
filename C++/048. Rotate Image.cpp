/* You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Note:
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
 * DO NOT allocate another 2D matrix and do the rotation.
 * Example 1:
 * Given input matrix = 
 * [
 *   [1,2,3],
 *   [4,5,6],
 *   [7,8,9]
 * ],
 * rotate the input matrix in-place such that it becomes:
 * [
 *   [7,4,1],
 *   [8,5,2],
 *   [9,6,3]
 * ]
 * Example 2:
 * Given input matrix =
 * [
 *   [ 5, 1, 9,11],
 *   [ 2, 4, 8,10],
 *   [13, 3, 6, 7],
 *   [15,14,12,16]
 * ], 
 * rotate the input matrix in-place such that it becomes:
 * [
 *   [15,13, 2, 5],
 *   [14, 3, 4, 1],
 *   [12, 6, 8, 9],
 *   [16, 7,10,11]
 * 
 * ]
 * https://leetcode.com/problems/rotate-image/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4389572.html
 *
 * Author: Adam Yu Wen
 * Date: June 28, 2018
 */

// Method 1:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int num = matrix.size();
        for (int i = 0; i < num / 2; i++) {
            for (int j = i; j < num - i - 1; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[num - j - 1][i];
                matrix[num - j - 1][i] = matrix[num - i - 1][num - j - 1];
                matrix[num - i - 1][num - j - 1] = matrix[j][num - i - 1];
                matrix[j][num - i - 1] = tmp;
            }
        }
    }
};


// Method 2:
// Flip by diagonal, then flip by central vertical line.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
};
