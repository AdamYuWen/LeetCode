/* On a plane there are n points with integer coordinates points[i] = [xi, yi]. Your task is to find the
 * minimum time in seconds to visit all points.
 * You can move according to the next rules:
 * In one second always you can either move vertically, horizontally by one unit or diagonally (it means
 * to move one unit vertically and one unit horizontally in one second).
 * You have to visit the points in the same order as they appear in the array.
 * Example 1:
 *	Input: points = [[1,1],[3,4],[-1,0]]
 *	Output: 7
 *	Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
 *	Time from [1,1] to [3,4] = 3 seconds 
 *	Time from [3,4] to [-1,0] = 4 seconds
 *	Total time = 7 seconds
 * Example 2:
 *	Input: points = [[3,2],[-2,2]]
 *	Output: 5
 * Constraints:
 *	points.length == n
 *	1 <= n <= 100
 *	points[i].length == 2
 *	-1000 <= points[i][0], points[i][1] <= 1000
 * https://leetcode.com/problems/minimum-time-visiting-all-points/
 *
 * Author: Adam Yu Wen
 * Date: November 26, 2019
 */

// Method 1:
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        if (points.size() == 0 || points.size() == 1) return res;
        for (int i = 1; i < points.size(); ++i) {
            // Next point is at the left up corner.
            while (points[i][0] < points[i - 1][0] && points[i][1] > points[i - 1][1]) {
                --points[i - 1][0];
                ++points[i - 1][1];
                ++res;
            }
            // Next point is at the left lower corner.
            while (points[i][0] < points[i - 1][0] && points[i][1] < points[i - 1][1]) {
                --points[i - 1][0];
                --points[i - 1][1];
                ++res;
            }
            // Next point is at the right up corner.
            while (points[i][0] > points[i - 1][0] && points[i][1] > points[i - 1][1]) {
                ++points[i - 1][0];
                ++points[i - 1][1];
                ++res;
            }
            // Next point is at the right down corner.
            while (points[i][0] > points[i - 1][0] && points[i][1] < points[i - 1][1]) {
                ++points[i - 1][0];
                --points[i - 1][1];
                ++res;
            }
            
            res += abs(points[i][0] - points[i - 1][0]) + abs(points[i][1] - points[i - 1][1]);
        }
        return res;
    }
};

// Method 2:
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        if (points.size() == 0 || points.size() == 1) return res;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] != points[i - 1][0] && points[i][1] != points[i - 1][1]) {
                int move_horizontal = points[i][0] - points[i - 1][0];
                int move_vertical = points[i][1] - points[i - 1][1];
                int min_step = min(abs(move_horizontal), abs(move_vertical));
                points[i - 1][0] += move_horizontal > 0 ? min_step : -min_step;
                points[i - 1][1] += move_vertical > 0 ? min_step : -min_step;
                res += min_step;
            }
            
            res += abs(points[i][0] - points[i - 1][0]) + abs(points[i][1] - points[i - 1][1]);
        }
        return res;
    }
};