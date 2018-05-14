/**
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one letter, like "Google".
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * Example 1:
 *		Input: "USA"
 *		Output: True
 * Example 2:
 *		Input: "FlaG"
 *		Output: False
 * Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 * https://leetcode.com/problems/detect-capital/#/description
 *
 * Author: Adam Yu Wen
 * Date: May 02, 2017
 */

class Solution {
public:
	// If letter is capital, return true
	bool isCapital(char C) {
		int CTemp = static_cast<int>(C);
		if (CTemp <= 90 && CTemp >= 65) return true;
		else return false;
	}

	// If letter is small, return true
	bool isSmall(char c) {
		int cTemp = static_cast<int>(c);
		if (cTemp <= 122 && cTemp >= 97) return true;
		else return false;
	}

	bool detectCapitalUse(string word) {
		// If word is only one letter and the letter is either capital or small one
		if (word.size() == 1 && (isCapital(word.at(0)) || isSmall(word.at(0)))) return true;
		else if (isCapital(word.at(0)) && isCapital(word.at(1))) {
			// Start with two capital letters
			int i;
			for (i = 2; i < word.size(); i++) {
				if (!(isCapital(word.at(i)))) {
					return false;
					break;
				}
			}
			if (i == word.size()) return true;
		}
		else if ((isCapital(word.at(0)) || isSmall(word.at(0))) && isSmall(word.at(1))) {
			// Start with a capital or small letter and a small letter
			int i;
			for (i = 2; i < word.size(); i++) {
				if (!(isSmall(word.at(i)))) {
					return false;
					break;
				}
			}
			if (i == word.size()) return true;
		}
		else return false;
	}
};