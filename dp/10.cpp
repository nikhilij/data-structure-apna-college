#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (const string& email: emails) {
            int pos = 0;
            
            string formattedEmail;
            while (email[pos] != '@') {
                if (email[pos] == '+') break;
                if (email[pos] == '.') { /* do nothing */ }
                else formattedEmail.push_back(email[pos]);
                pos++;
            }

            formattedEmail += email.substr(email.find("@"));

            uniqueEmails.insert(formattedEmail);
        }

        return uniqueEmails.size();
    }
};

int main() {
    Solution solution;
    vector<string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
    cout << solution.numUniqueEmails(emails) << endl;
    return 0;
}