/**
 * Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 * Each letter in the magazine string can only be used once in your ransom note.
 * Note: You may assume that both strings contain only lowercase letters.
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * https://leetcode.com/problems/ransom-note/
 *
 * Author: Adam Yu Wen
 * Date: October 28, 2016
 */

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> myMap;
		for (int i = 0; i< magazine.size(); i++) {
			myMap[magazine[i]]++;
		}
		for (int i = 0; i < ransomNote.size(); i++) {
			if (--myMap[ransomNote[i]] < 0) return false;
		}
		return true;
	}
};