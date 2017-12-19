/* Initially, there is a Robot at position (0, 0). Given a sequence of its moves,
 * judge if this robot makes a circle, which means it moves back to the original place.
 * The move sequence is represented by a string. And each move is represent by a
 * character. The valid robot moves are R (Right), L (Left), U (Up) and D (down).
 * The output should be true or false representing whether the robot makes a circle.
 * Example 1:
 *	Input: "UD"
 *	Output: true
 * Example 2:
 *	Input: "LL"
 *	Output: false
 * https://leetcode.com/problems/judge-route-circle/description/
 *
 * Author: Adam Yu Wen
 * Date: December 19, 2017
 */

class Solution {
public:
	bool judgeCircle(string moves) {
		int horizontal = 0;
		int vertical = 0;
		for (int idx = 0; idx < moves.size(); idx++) {
			switch (moves[idx]) {
			case 'R': { horizontal++; break; }
			case 'L': { horizontal--; break; }
			case 'U': { vertical++; break; }
			case 'D': { vertical--; break; }
			}
		}
		return (horizontal == 0 && vertical == 0);
	}
};