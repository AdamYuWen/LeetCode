/**
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * Return [1,3,3,1].
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 * Author: Adam Yu Wen
 * Date: July 13, 2017
 */

 /**
  * This solution is very similar with 118. Pascal's Triangle.
  * Notice: rowIndex in this case is less than numRows by 1.
  * For example, if numRows = 1 in question 118
  *              the rowIndex = 0 in this question
  */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        vector<int> row;
        for(int rowIdx = 0; rowIdx < rowIndex + 1; rowIdx++) {
            for(int colIdx = 0; colIdx < rowIdx + 1; colIdx++) {
                if(colIdx == 0) row.push_back(1);
                else if(colIdx == rowIdx) row.push_back(1);
                else row.push_back(res[rowIdx - 1][colIdx - 1] + res[rowIdx - 1][colIdx]);
            }
            if(rowIdx == rowIndex) return row;
            res.push_back(row);
            row.clear();
        }
    }
};
