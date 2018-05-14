/**
 * Given n, how many structurally unique BST's (binary search trees) that
 * store values 1...n?
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *   1         3     3      2      1
 *    \       /     /      / \      \
 *     3     2     1      1   3      2
 *    /     /       \                 \
 *   2     1         2                 3
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * Author: Adam Yu Wen
 * Date: April 6, 2018
 */

// Method 1:
// It is slow, which takes 108 ms.
class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) return 1;
        switch (n) {
            case 2: return 2;
            case 3: return 5;
            case 4: return 14;
            case 5: return 42;
        }
        int res = 0;
        for (int idx = 1; idx < n + 1; idx++) {
            res += numTrees(idx - 1) * numTrees(n - idx);
        }
        return res;
    }
};

// Method 2:
// It takes 2 ms, which beats 100% of cpp submissions.
class Solution {
public:
    int numTrees(int n) {
        vector<int> resList;
        for (int i = 0; i < n + 1; i++) {
            if (i == 0 || i == 1) {
                resList.push_back(1);
            }
            else {
                int res = 0;
                for (int j = 0; j < i; j++) {
                    res += resList[j] * resList[i - 1 - j];
                }
                resList.push_back(res);
            }
        }
        return resList.back();
    }
};
