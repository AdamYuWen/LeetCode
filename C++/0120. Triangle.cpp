/* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 * https://leetcode.com/problems/triangle/description/
 *
 * Author: Adam Yu Wen
 * Date: August 22, 2018
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res = INT_MAX;
        int triangleSize = triangle.size();
        vector<int> minSumList;
        vector<int> prevMinSumList;
        
        for (int row = 0; row < triangleSize; row++) {
            minSumList.push_back(INT_MAX);
            for (int i = 0; i < row + 1; i++) {
                if (i == 0) {
                    // If it is the first element in the row
                    if (row == 0) {
                        minSumList[i] = triangle[row][i];
                    }
                    else {
                        minSumList[i] += triangle[row][i];
                    }
                }
                else if (i == row) {
                    // If it is the last element in the row
                    minSumList[i] = prevMinSumList[i - 1] + triangle[row][i];
                }
                else {
                    // If it is the middle elements in the row
                    minSumList[i] = min(prevMinSumList[i - 1], prevMinSumList[i]) + triangle[row][i];
                }
            }
            prevMinSumList = minSumList;
        }
        
        for (int i = 0, minSumListSize = minSumList.size(); i < minSumListSize; i++) {
            res = min(minSumList[i], res);
        }
        
        return res;
    }
};
