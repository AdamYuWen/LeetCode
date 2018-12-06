/* Every email consists of a local name and a domain name, separated by the @ sign.
 * For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
 * Besides lowercase letters, these emails may contain '.'s or '+'s.
 * 
 * If you add periods ('.') between some characters in the local name part of an email address, mail
 * sent there will be forwarded to the same address without dots in the local name.  For example,
 * "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that
 * this rule does not apply for domain names.)
 * 
 * If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
 * This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to
 * my@email.com.  (Again, this rule does not apply for domain names.)
 * 
 * It is possible to use both of these rules at the same time.
 * 
 * Given a list of emails, we send one email to each address in the list.  How many different addresses
 * actually receive mails? 
 * 
 * Example 1:
 * Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
 * Output: 2
 * Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 * Note:
 * 1 <= emails[i].length <= 100
 * 1 <= emails.length <= 100
 * Each emails[i] contains exactly one '@' character.
 * https://leetcode.com/problems/unique-email-addresses/
 *
 * Author: Adam Yu Wen
 * Date: December 6, 2018
 */

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> mp;
        for (int idx = 0; idx < emails.size(); idx++) {
            // Separate local name and domain name
            size_t atPos = emails[idx].find("@");
            string str1 = emails[idx].substr(0, atPos);
            string str2 = emails[idx].substr(atPos);
            
            // Remove all periods
            while (str1.find(".") != string::npos) {
                str1 = str1.erase(str1.find("."), 1);
            }
            
            // Remove everything after the first plus
            if (str1.find("+") != string::npos) {
                str1 = str1.substr(0, str1.find("+"));
            }
            
            mp[str1 + str2]++;
        }
        return mp.size();
    }
};
