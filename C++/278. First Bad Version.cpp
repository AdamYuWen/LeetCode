/* You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product fails the quality check. Since
 * each version is developed based on the previous version, all the versions after
 * a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first
 * bad one, which causes all the following ones to be bad.
 * You are given an API bool isBadVersion(version) which will return whether version
 * is bad. Implement a function to find the first bad version. You should minimize
 * the number of calls to the API.
 * Example:
 * Given n = 5
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * Then 4 is the first bad version.
 * https://leetcode.com/problems/first-bad-version/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 20, 2018
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        if (isBadVersion(l) == true)
            return 1;
        while (l + 1 != r) {
            // Leetcode doesn't accept (l + r) / 2
            int m = l + (r - l) / 2;
            if (isBadVersion(m) == false) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return r;
    }
};
