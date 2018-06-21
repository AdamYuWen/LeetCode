/* You have a list of points in the plane. Return the area of the largest triangle that can be
 * formed by any 3 of the points.
 * Example:
 * Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * Output: 2
 * Explanation: 
 * The five points are show in the figure below. The red triangle is the largest.
 * 
 * Notes:
 * 3 <= points.length <= 50.
 * No points will be duplicated.
 *  -50 <= points[i][j] <= 50.
 * Answers within 10^-6 of the true value will be accepted as correct.
 *
 * Author: Adam Yu Wen
 * Date: June 21, 2018
 */

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        int pointsSize = points.size();
        for (int i = 0; i < pointsSize; i++) {
            for (int j = i + 1; j < pointsSize; j++) {
                for (int k = j + 1; k < pointsSize; k++) {
                    res = max(res, triangleArea(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }
    
    double triangleArea(vector<int> &point1, vector<int> &point2, vector<int> &point3) {
        return abs((point1[0] * (point2[1] - point3[1]) + point2[0] * (point3[1] - point1[1]) +
                    point3[0] * (point1[1] - point2[1])) / 2.0);
    }
};
