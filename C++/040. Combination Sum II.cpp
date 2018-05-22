/* Given a collection of candidate numbers (candidates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
 * Each number in candidates may only be used once in the combination.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 * Example 2:
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 *   [1,2,2],
 *   [5]
 * ]
 * https://leetcode.com/problems/combination-sum-ii/description/
 * Reference: http://www.cnblogs.com/grandyang/p/4419386.html
 * 
 * Author: Adam Yu Wen
 * Date: May 22, 2018
 */

// Method 1:
// It is slow, which takes 169 ms.
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        // Add a empty set into the allSetsLessTarget
        vector<vector<int>> allSetsLessTarget(1);
        vector<vector<int>> res;
        
        int candidatesSize = candidates.size();
        for (int j = 0; j < candidatesSize; j++) {
            int allSetsLessTargetSize = allSetsLessTarget.size();
            for (int i = 0; i < allSetsLessTargetSize; i++) {
                // Possible add-in vector
                vector<int> addIn = allSetsLessTarget[i];
                addIn.push_back(candidates[j]);
                
                int sum = 0;
                for(auto num : addIn) {
                    sum += num;
                    // If sum > target, don't need to add more numbers
                    if (sum > target)
                        break;
                }
                // If the sum of a list is target, add the list to res
                if (sum == target) {
                    res.push_back(addIn);
                }
                // If the sum of a list is less than target, add the lsit to allSetsLessTarget
                else if (sum < target) {
                    allSetsLessTarget.push_back(addIn);
                }
            }
        }
        
        // Remove all duplicate lists
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};


// Method 2:
// It takes 10 ms, which beats 96.20% of cpp submitions.
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, target, 0, out, res);
        return res;
    }
    
    void combinationSum2Helper(vector<int> &candidate, int target, int idx, vector<int> &out, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(out);
        } else {
            for (int i = idx; i < candidate.size(); i++) {
                if (candidate[i] > target) {
                    break;
                } else if (i != idx && candidate[i] == candidate[i - 1]) {
                    // i != idx ==> it is allowed to use duplicate numbers
                    continue;
                } 
                else {
                    out.push_back(candidate[i]);
                    combinationSum2Helper(candidate, target - candidate[i], i + 1, out, res);
                    out.pop_back();
                }
            }
        }
    }
};
