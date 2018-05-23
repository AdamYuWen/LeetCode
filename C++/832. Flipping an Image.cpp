/* Given a binary matrix A, we want to flip the image horizontally, then invert it,
 * and return the resulting image.
 * To flip an image horizontally means that each row of the image is reversed.  For
 * example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by
 * 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 * Example 1:
 * Input: [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 * Example 2:
 * Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Notes:
 * 1 <= A.length = A[0].length <= 20
 * 0 <= A[i][j] <= 1
 * https://leetcode.com/problems/flipping-an-image/description/
 *
 * Author: Adam Yu Wen
 * Date: May 23, 2018
 */

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
	// Choose auto x when you want to work with copies.
	// Choose auto &x when you want to work with original items and may modify them.
	// Choose auto const &x when you want to work with original items and will not modify them.
        for (auto &row : A) {
            int l = 0;
            int r = row.size() - 1;
            while (l < r) {
                int tmp = row[l];
                row[l] = row[r];
                row[r] = tmp;
                l++;
                r--;
            }
            for (int i = 0; i < row.size(); i++) {
                if (row[i] == 0)
                    row[i] = 1;
                else
                    row[i] = 0;
            }
        }
        return A;
    }
};
