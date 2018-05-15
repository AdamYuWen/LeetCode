/* Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum
 * minutes difference between any two time points in the list.
 * Example 1:
 * Input: ["23:59","00:00"]
 * Output: 1
 * Note:
 * The number of time points in the given list is at least 2 and won't exceed 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * https://leetcode.com/problems/minimum-time-difference/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 15, 2018
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        int timePointsSize = timePoints.size();
        for (int i = 0; i < timePointsSize; i++) {
            for (int j = i + 1; j < timePointsSize; j++) {
                int diff = abs(convertMin(timePoints[i]) - convertMin(timePoints[j]));
                // 1440 = 24 * 60
                res = min(res, min(diff, 1440 - diff));
                // if res == 0, there is no less time difference
                if (res == 0) return res;
            }
        }
        return res;
    }
    
    int convertMin(string time) {
        int hours = stoi(time.substr(0, 2));
        int mins = stoi(time.substr(3, 2));
        return hours * 60 + mins;
    }
};
