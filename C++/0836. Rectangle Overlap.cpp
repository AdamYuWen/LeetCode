/* A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the
 * coordinates of its bottom-left corner, and (x2, y2) are the coordinates of
 * its top-right corner.
 * Two rectangles overlap if the area of their intersection is positive.  To be
 * clear, two rectangles that only touch at the corner or edges do not overlap.
 * Given two rectangles, return whether they overlap.
 * Example 1:
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 * Example 2:
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 * Notes:
 * Both rectangles rec1 and rec2 are lists of 4 integers.
 * All coordinates in rectangles will be between -10^9 and 10^9.
 * https://leetcode.com/contest/weekly-contest-85/problems/rectangle-overlap/
 * 
 * Author: Adam Yu Wen
 * Date: May 19, 2018
 */

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int firstBLX = rec1[0];
        int firstBLY = rec1[1];
        int firstTRX = rec1[2];
        int firstTRY = rec1[3];
        
        int secondBLX = rec2[0];
        int secondBLY = rec2[1];
        int secondTRX = rec2[2];
        int secondTRY = rec2[3];
        
        if ((secondBLX < firstTRX && secondBLY < firstTRY) && (secondTRX > firstBLX && secondTRY > firstBLY))
            return true;
        else
            return false;
    }
};
