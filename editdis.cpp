// Problem description

// Given two strings string1, string2 and some edit operations. 
// Write an algorithm to find the minimum number of operations required to convert string1 to string2.

// The allowed operations are:
// Insertion — Insert a new character.
// Deletion — Delete a character.
// Substitution — Replace one character by another.

// Input : string1 = "horse", string2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

#include <iostream>
#include <string>
using namespace std;

class EditDistance {
public:
    // Driver function
    int editDistance(string word1, string word2) {
        if (word1.empty()) 
            return word2.length();
        if (word2.empty()) 
            return word1.length();
        return match(word1, word2, 0, 0);
    }

    // Helper function
    int match(string s1, string s2, int i, int j) {
        // If one of the string's pointer has reached the end of it
        if (i == s1.length())
            return s2.length() - j;
        if (j == s2.length())
            return s1.length() - i;

        int result;

        // If the current position is the same.
        if (s1[i] == s2[j]) {
            result = match(s1, s2, i + 1, j + 1);
        } else {
            // Case1: insert
            int insert = match(s1, s2, i, j + 1);
            // Case2: delete
            int remove = match(s1, s2, i + 1, j);
            // Case3: substitute
            int substitute = match(s1, s2, i + 1, j + 1);

            result = min(insert, min(remove, substitute)) + 1;
        }
        return result;
    }
};

int main() {
    EditDistance ed;
    int n = ed.editDistance("meet", "minee");
    cout << n << endl;
    return 0;
}
