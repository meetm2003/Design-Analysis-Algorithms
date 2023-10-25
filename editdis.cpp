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

// brute force approach 

#include <iostream>
#include <string>
using namespace std;

class EditDistance {
public:
    int editDistance(string word1, string word2, int m, int n) {
        int dp[m+1][n+1];
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                // if string is empty...
                if(i == 0){
                    dp[i][j] = j;
                }
                else if(j == 0){
                    dp[i][j] = i;
                }
                // if char are same of both string... 
                else if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // if we need to do operation...
                else{
                    dp[i][j] = 1 + min(dp[i][j - 1], // insert
                                       min(dp[i - 1][j], // remove
                                       dp[i - 1][j - 1])); // replace
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    EditDistance ed;
    string s1 = "horse";
    string s2 = "ros";
    int n = ed.editDistance(s1, s2, s1.length(),s2.length());
    cout << n << endl;
    return 0;
}
