/**
 * Given an array nums containing n + 1 integers where each integer is between 1 and n
 * (inclusive), prove that at least one duplicate number must exist. Assume that there is
 * only one duplicate number, find the duplicate one.
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * Author: Adam Yu Wen
 * Date: April 12, 2018
 */

// Method 1:
// It takes 429 ms, which is slow.
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int numsSize = nums.size();
		for (int i = 0; i < numsSize; i++) {
			for (int j = i + 1; j < numsSize; j++) {
				if (nums[i] == nums[j]) {
					return nums[i];
				}
			}
		}
	}
};

// Method 2:
// It takes 15 ms, but it modifies the array.
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int numsSize = nums.size();
		for (int idx = 0; idx < numsSize - 1; idx++) {
			if (nums[idx] == nums[idx + 1]) {
				return nums[idx];
			}
		}
	}
};

// Method 3:
// The best solution in LeetCode.
/* The first while loop ensures you goes in the correct cycle which has duplicates.
 * For example: index = [0 1 2 3 4 5 6 7]; nums=[5 2 1 3 5 7 6 4].
 * (slow)nums[slow] = (0)5 (5)7 (7)4 (4)5; fast = (0)5 (7)4 (5)7 (4)5;
 * ----> when they meets at (idx=4)(value=5), you know you have a cycle.
 * Take a look at the cycle by the indices and values:
 * idx: 0—>5—>7—>4–>(goes back to idx=5)
 * val: 5—>7—>4—>5–>(goes back to val=7)
 * The second while loop will stop when “t=0” and “slow=4” (their values = 5, the duplicate number).
 * The duplicate number 5 is the reason why the two pointers will meet at a same index (next number).
 * In fact, the second loop will always stop right before they meet at the first item of the cycle.
 * (This is very similar to the problem Linked List Cycle II. )
 */

/* Another example:
 * nums = [2,1,3,1], then the mapping function is 0->2, {1,3}->1, 2->3. Then the sequence we get
 * definitely has a cycle. 0->2->3->1->1->1->1->1->........ The starting point of this cycle is
 * the duplicate number.
 * We can use Floyd’s Tortoise and Hare Algorithm to find the starting point.
 * According to Floyd’s algorithm, first step, if a cycle does exist, and you advance the tortoise
 * one node each unit of time but the hare two nodes each unit of time, then they will eventually
 * meet. This is what the first while loop does. The first while loop finds their meeting point.
 * Second step, take tortoise or hare to the start point of the list (i.e. let one of the animal
 * be 0) and keep the other one staying at the meeting point. Now, advance both of the animals
 * one node each unit of time, the meeting point is the starting point of the cycle. This is what
 * the second while loop does. The second while loop finds their meeting point.
 * Proof of second step:
 * Distance traveled by tortoise while meeting = x + y
 * Distance traveled by hare while meeting = (x + y + z) + y = x + 2y + z
 * Since hare travels with double the speed of tortoise,
 * so 2(x+y)= x+2y+z => x+2y+z = 2x+2y => x=z
 * Hence by moving tortoise to start of linked list, and making both animals to move one node at
 * a time, they both have same distance to cover .
 * They will reach at the point where the loop starts in the linked list
 */
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0, t = 0;
		while (true) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) break;
		}
		while (true) {
			slow = nums[slow];
			t = nums[t];
			if (t == slow) break;
		}
		return t;
	}
};