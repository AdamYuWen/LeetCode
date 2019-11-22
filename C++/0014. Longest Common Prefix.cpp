/* Write a function to find the longest common prefix string amongst an array of strings.
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * Author: Adam Yu Wen
 * Date: December 21, 2017
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        int endIdx = 0;
        for (unsigned int singleIdx = 0; singleIdx < strs[0].size(); singleIdx++) {
            for (unsigned int strIdx = 1; strIdx < strs.size(); strIdx++) {
                if (strs[strIdx][singleIdx] != strs[0][singleIdx]) {
                    endIdx = singleIdx;
                    goto endloop;
                }
                else {
                    endIdx = singleIdx + 1;
                }
            }
        }

    endloop:
        return strs[0].substr(0, endIdx);
    }
};
