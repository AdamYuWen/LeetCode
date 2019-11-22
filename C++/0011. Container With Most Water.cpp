/* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate
 * (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and
 * (i, 0). Find two lines, which together with x-axis forms a container, such that the container
 * contains the most water.
 * Note: You may not slant the container and n is at least 2.
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * Author: Adam Yu Wen
 * Date: June 27, 2018
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int smallHeight = min(height[l], height[r]);
            res = max(res, smallHeight * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
