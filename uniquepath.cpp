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
        std::vector<int> dp(n);
        dp[0] = 1; // starting point
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
int main(){
    uniquepath un;
    int n = un.up(3,2);
    cout<<n<<endl;
}

// time complexity :: O(mn)
// space complexity :: O(n)