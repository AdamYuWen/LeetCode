/* Given a 2D integer matrix M representing the gray scale of an image, you need
 * to design a smoother to make the gray scale of each cell becomes the average
 * gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell
 * has less than 8 surrounding cells, then use as many as you can.
 * Example 1:
 * Input:
 * [[1,1,1],
 *  [1,0,1],
 *  [1,1,1]]
 * Output:
 * [[0, 0, 0],
 *  [0, 0, 0],
 *  [0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 * Note:
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 * https://leetcode.com/problems/image-smoother/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 31, 2018
 */

// Method 1:
// It takes 167 ms, which beats 99.16% of cpp submissions.
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res = M;

        // Matrix is blank.
        if (M.size() == 0) return M;

        // Matrix is a row vector.
        if (M.size() == 1) {
            // There is only one element in the matrix.
            if (M[0].size() == 1) return M;
            for (int col = 0; col < M[0].size(); col++) {
                if (col == 0) {
                    res[0][col] = (M[0][0] + M[0][1]) / 2;
                }
                else if (col == M[0].size() - 1) {
                    res[0][col] = (M[0][col - 1] + M[0][col]) / 2;
                }
                else {
                    res[0][col] = (M[0][col - 1] + M[0][col] + M[0][col + 1]) / 3;
                }
            }
            return res;
        }

        // Matrix is a column vector.
        if (M[0].size() == 1) {
            for (int row = 0; row < M.size(); row++) {
                if (row == 0) {
                    res[row][0] = (M[0][0] + M[1][0]) / 2;
                }
                else if (row == M.size() - 1) {
                    res[row][0] = (M[row - 1][0] + M[row][0]) / 2;
                }
                else {
                    res[row][0] = (M[row - 1][0] + M[row][0] + M[row + 1][0]) / 3;
                }
            }
            return res;
        }

        // Matrix is a regular maxtix.
        for (int row = 0; row < M.size(); row++) {
            for (int col = 0; col < M[0].size(); col++) {
                if (row == 0 && col == 0) {
                    // left up corner
                    res[row][col] = (M[0][0] + M[0][1] + M[1][0] + M[1][1]) / 4;
                }
                else if (row == 0 && col == M[0].size() - 1) {
                    // right up corner
                    res[row][col] = (M[0][col - 1] + M[0][col] + M[1][col - 1] + M[1][col]) / 4;
                }
                else if (row == M.size() - 1 && col == 0) {
                    // left bottom corner
                    res[row][col] = (M[row][0] + M[row][1] + M[row - 1][0] + M[row - 1][1]) / 4;
                }
                else if (row == M.size() - 1 && col == M[0].size() - 1) {
                    // right bottom corner
                    res[row][col] = (M[row][col] + M[row - 1][col] + M[row][col - 1] + M[row - 1][col - 1]) / 4;
                }
                else if (row == 0) {
                    // the first row
                    res[row][col] = (M[row][col - 1] + M[row][col] + M[row][col + 1] +
                        M[row + 1][col - 1] + M[row + 1][col] + M[row + 1][col + 1]) / 6;
                }
                else if (row == M.size() - 1) {
                    // the last row
                    res[row][col] = (M[row - 1][col - 1] + M[row - 1][col] + M[row - 1][col + 1] +
                        M[row][col - 1] + M[row][col] + M[row][col + 1]) / 6;
                }
                else if (col == 0) {
                    // the first column
                    res[row][col] = (M[row - 1][col] + M[row - 1][col + 1] +
                        M[row][col] + M[row][col + 1] +
                        M[row + 1][col] + M[row + 1][col + 1]) / 6;
                }
                else if (col == M[0].size() - 1) {
                    res[row][col] = (M[row - 1][col - 1] + M[row - 1][col] +
                        M[row][col - 1] + M[row][col] +
                        M[row + 1][col - 1] + M[row + 1][col]) / 6;
                }
                else {
                    res[row][col] = (M[row - 1][col - 1] + M[row - 1][col] + M[row - 1][col + 1] +
                        M[row][col - 1] + M[row][col] + M[row][col + 1] +
                        M[row + 1][col - 1] + M[row + 1][col] + M[row + 1][col + 1]) / 9;
                }
            }
        }
        return res;
    }
};


// Method 2:
// The code is more clearer and shorter, but a little bit slower, which takes 194 ms.
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res = M;
        for (int row = 0; row < M.size(); row++) {
            for (int col = 0; col < M[0].size(); col++) {
                res[row][col] = average(row, col, M);
            }
        }
        return res;
    }
    
    int average(int x, int y, vector<vector<int>> &M) {
        int sum = 0, cnt = 0;
        for (int i = -1; i < 2; i++) {
            for (int j  = -1; j < 2; j++) {
                if (x + i > -1 && y + j > -1 && x + i < M.size() && y + j < M[0].size()) {
                    sum += M[x + i][y + j];
                    cnt++;
                }
            }
        }
        return sum / cnt;
    }
};
