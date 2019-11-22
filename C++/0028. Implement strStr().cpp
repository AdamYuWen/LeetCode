/* Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * Example 1:
 *	Input: haystack = "hello", needle = "ll"
 *	Output: 2
 * Example 2:
 *	Input: haystack = "aaaaa", needle = "bba"
 *	Output: -1
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * Author: Adam Yu Wen
 * Date: December 21, 2017
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;

        int haystackSize = haystack.size();
        int needleSize = needle.size();
        int hayIdx;
        for (hayIdx = 0; hayIdx < haystackSize - needleSize + 1; hayIdx++) {
            // Important: The ending point was changed from haystackSize to
            // (haystackSize - needleSize + 1), which saved a lot of time.
            if (haystack[hayIdx] == needle[0]) {
                int neeIdx;
                for (neeIdx = 0; neeIdx < needleSize; neeIdx++) {
                    if (haystack[hayIdx + neeIdx] != needle[neeIdx]) {
                        break;
                    }
                }
                if (neeIdx == needle.size())
                    return hayIdx;
            }
        }
        return -1;
    }
};
