/* Given an array of strings, group anagrams together.
 * Example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * Author: Adam Yu Wen
 * Date: May 14, 2018
 */

// Method 1:
// 100/101 test cases passed.
// The only one is Time Limit Exceeded.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        while (!strs.empty()) {
            // target is the first element in the string
            unordered_map<char, int> target = convertToCode(strs[0]);
            int targetSize = strs[0].size();
            
            // put every group members into resTmp
            vector<string> resTmp;
            int strsSize = strs.size();
            // start from the last one, because we will erase group members
            // if we start from the first one, the index number will be changed
            for (int i = strsSize - 1; i > -1; i--) {
                // if the size is not the same, they are not in the same group
                if (strs[i].size() != targetSize) continue;
                else {
                    unordered_map<char, int> code = convertToCode(strs[i]);
                    if (target == code) {
                        resTmp.push_back(strs[i]);
                        strs.erase(strs.begin() + i);
                    }
                }
            }
            res.push_back(resTmp);
        }
        return res;
    }
    
    unordered_map<char, int> convertToCode(string str) {
        unordered_map<char, int> res;
        int strSize = str.size();
        for (int i = 0; i < strSize; i++) {
            res[str[i]]++;
        }
        return res;
    }
};


// Method 2:
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto str : strs) {
            string tmpStr = str;
            sort(tmpStr.begin(), tmpStr.end());
	    // even though there is no tmpStr in the map,
	    // it still can push_back
            mp[tmpStr].push_back(str);
        }
        for (auto item = mp.begin(); item != mp.end(); item++) {
            res.push_back(item->second);
        }
        return res;
    }
};
