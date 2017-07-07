/**
 * Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
 * Example 1:
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
 * For the left two athletes, you just need to output their relative ranks according to their scores.
 * Note:
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 *
 * Author: Adam Yu Wen
 * Date: July 07, 2017
 */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res;
        vector<int> afterSort = nums;
        sort(afterSort.begin(), afterSort.end());

        for(unsigned int idx = 0; idx < nums.size(); idx++) {
            vector<int>::iterator it = find(afterSort.begin(), afterSort.end(), nums.at(idx));
            // If "it" is pointing to the last element, which means it is the largest
            if(it == afterSort.end() - 1) res.push_back("Gold Medal");
            else if(it == afterSort.end() - 2) res.push_back("Silver Medal");
            else if(it == afterSort.end() - 3) res.push_back("Bronze Medal");
            else res.push_back(to_string(afterSort.end() - it));
        }

        return res;
    }
};
