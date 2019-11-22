/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 * Author: Adam Yu Wen
 * Date: July 13, 2017
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> row;
        for(int rowIdx = 0; rowIdx < numRows; rowIdx++) {
            for(int colIdx = 0; colIdx < rowIdx + 1; colIdx++) {
                if(colIdx == 0) row.push_back(1);
                else if(colIdx == rowIdx) row.push_back(1);
                else row.push_back(res[rowIdx - 1][colIdx] + res[rowIdx - 1][colIdx - 1]);
            }
            res.push_back(row);
            // it is important to clear row vector
            row.clear();
        }
        return res;
    }
};
