/**
 * You are standing at position 0 on an infinite number line. There is a goal at position target.
 * On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.
 * Return the minimum number of steps required to reach the destination.
 * Example 1:
 *	Input: target = 3
 *	Output: 2
 *	Explanation:
 *	On the first move we step from 0 to 1.
 *	On the second step we step from 1 to 3.
 * Example 2:
 *	Input: target = 2
 *	Output: 3
 *	Explanation:
 *	On the first move we step from 0 to 1.
 *	On the second move we step  from 1 to -1.
 *	On the third move we step from -1 to 2.
 * Note:
 *	target will be a non-zero integer in the range [-10^9, 10^9].
 * https://leetcode.com/problems/reach-a-number/description/
 * Reference: http://www.cnblogs.com/grandyang/p/8456022.html
 *
 * Author: Adam Yu Wen
 * Date: April 18, 2018
 */

class Solution {
public:
	int reachNumber(int target) {
		target = abs(target);
		int currSum = 0;
		int step = 0;
		while (currSum < target) {
			step++;
			currSum += step;
		}
		if (currSum == target) return step;
		// the difference is odd
		if ((currSum - target) % 2) {
			// the step is odd
			if (step % 2)
				return step + 2;
			// the step is even
			else
				return step + 1;
		}
		// the difference is even
		else {
			return step;
		}
	}
};