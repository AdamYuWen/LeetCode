/* A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.
 * We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
 * The rules of Goat Latin are as follows:
 * If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
 * For example, the word 'apple' becomes 'applema'.
 * If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
 * For example, the word "goat" becomes "oatgma".
 * Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
 * For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
 * Return the final sentence representing the conversion from S to Goat Latin. 
 * Example 1:
 * Input: "I speak Goat Latin"
 * Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * Example 2:
 * Input: "The quick brown fox jumped over the lazy dog"
 * Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 * Notes:
 * S contains only uppercase, lowercase and spaces. Exactly one space between each word.
 * 1 <= S.length <= 150.
 * https://leetcode.com/problems/goat-latin/description/
 *
 * Author: Adam Yu Wen
 * Date: May 31, 2018
 */

// Method 1:
class Solution {
public:
    string toGoatLatin(string S) {
        string res = "", word = "";
        int cntWord = 0;
        istringstream iss(S);
        while (iss >> word) {
            cntWord++;
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' ||
                word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U') {
                word += "ma";
            } else {
                word = word.substr(1, word.size()) + word[0] + "ma";
            }
            for (int i = 0; i < cntWord; i++) {
                word += 'a';
            }
            res += ' ' + word;
        }
        return res.substr(1);
    }
};


// Method 2:
// Using unordered_set will make the program faster, which takes 6 ms.
class Solution {
public:
    string toGoatLatin(string S) {
        string res = "", word = "";
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int cntWord = 0;
        istringstream iss(S);
        while (iss >> word) {
            cntWord++;
            if (vowel.count(word[0])) {
                word += "ma";
            } else {
                word = word.substr(1, word.size()) + word[0] + "ma";
            }
            for (int i = 0; i < cntWord; i++) {
                word += 'a';
            }
            res += ' ' + word;
        }
        return res.substr(1);
    }
};
