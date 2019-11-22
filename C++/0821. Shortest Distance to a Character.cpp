/* Given a string S and a character C, return an array of integers representing the shortest distance
 * from the character C in the string.
 * 
 * Example 1:
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 *  
 * Note:
 * S string length is in [1, 10000].
 * C is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
 * https://leetcode.com/problems/shortest-distance-to-a-character/
 * 
 * Author: Adam Yu Wen
 * Date: December 12, 2018
 */

// Method 1:
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        
        // Create a vector for all index of target char
        vector<int> charIdx;
        size_t found = S.find(C);
        while (found != string::npos) {
            charIdx.push_back(found);
            found = S.find(C, found + 1);
        }
        
        // If C is in S
        int l = 0, r = 1;
        for (int idx = 0; idx < S.size(); idx++) {
            if (charIdx.size() == 1) {
                // There is only one C in S
                res.push_back(abs(idx - charIdx[0]));
            } else {
                // There are at lease two C in S
                res.push_back(min(abs(idx - charIdx[l]), abs(idx - charIdx[r])));
                if (idx == charIdx[r] & r < charIdx.size() - 1) {
                    l++;
                    r++;
                }
            }
        }
        
        return res;
    }
};


// Method 2:
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        for (int idx = 0; idx < S.size(); idx++) {
            int foundBefore = S.find_last_of(C, idx);
            int foundAfter = S.find_first_of(C, idx);
            
            if (foundBefore != string::npos && foundAfter != string::npos) {
                res.push_back(min(abs(idx - foundBefore), abs(idx - foundAfter)));
            } else if (foundBefore != string::npos) {
                
                res.push_back(abs(idx - foundBefore));
            } else {
                res.push_back(abs(idx - foundAfter));
            }
        }
        return res;
    }
};
