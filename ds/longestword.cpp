// wap to find the longest word in the sentence 
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;
    string longestWord = "";
    size_t maxLength = 0;

    while (ss >> word) {
        if (word.length() >= maxLength) {
            maxLength = word.length();
            longestWord = word;
        }
    }

    cout << "The longest word is: " << longestWord << endl;
    return 0;
}
