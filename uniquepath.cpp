//A robot is located at the top-left corner of a m x n grid 

//The robot can only move either down or right at any point in time. 
//The robot is trying to reach the bottom-right corner of the grid 

//Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right

#include<iostream>
#include<vector>
using namespace std;

class uniquepath{
   public:
    int up(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
int main(){
    uniquepath un;
    int n = un.up(3,2);
    cout<<n<<endl;
}

// time complexity :: O(mn)
// space complexity :: O(m)
