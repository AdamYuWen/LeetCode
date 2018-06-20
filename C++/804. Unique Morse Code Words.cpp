/* International Morse Code defines a standard encoding where each letter is mapped
 * to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...",
 * "c" maps to "-.-.", and so on.
 * For convenience, the full table for the 26 letters of the English alphabet is given
 * below:
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
 *  "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * Now, given a list of words, each word can be written as a concatenation of the
 * Morse code of each letter. For example, "cab" can be written as "-.-.-....-", (which
 * is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the
 * transformation of a word.
 * Return the number of different transformations among all words we have.
 * Example:
 * Input: words = ["gin", "zen", "gig", "msg"]
 * Output: 2
 * Explanation: 
 * The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * There are 2 different transformations, "--...-." and "--...--.".
 * Note:
 * The length of words will be at most 100.
 * Each words[i] will have length in range [1, 12].
 * words[i] will only consist of lowercase letters.
 * https://leetcode.com/problems/unique-morse-code-words/description/
 * 
 * Author: Adam Yu Wen
 * Date: June 20, 2018
 */

// It takes 6 ms, which beats 99.70% of cpp submissions.
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> res;
        unordered_map<char, string> charMp;
        charMp['a'] = ".-";
        charMp['b'] = "-...";
        charMp['c'] = "-.-.";
        charMp['d'] = "-..";
        charMp['e'] = ".";
        charMp['f'] = "..-.";
        charMp['g'] = "--.";
        charMp['h'] = "....";
        charMp['i'] = "..";
        charMp['j'] = ".---";
        charMp['k'] = "-.-";
        charMp['l'] = ".-..";
        charMp['m'] = "--";
        charMp['n'] = "-.";
        charMp['o'] = "---";
        charMp['p'] = ".--.";
        charMp['q'] = "--.-";
        charMp['r'] = ".-.";
        charMp['s'] = "...";
        charMp['t'] = "-";
        charMp['u'] = "..-";
        charMp['v'] = "...-";
        charMp['w'] = ".--";
        charMp['x'] = "-..-";
        charMp['y'] = "-.--";
        charMp['z'] = "--..";

        string morseWord = "";
        for (auto word : words) {
            for (int i = 0; i < word.size(); i++) {
                morseWord += charMp[word[i]];
            }
            res.insert(morseWord);
            morseWord = "";
        }
        return res.size();
    }
};
