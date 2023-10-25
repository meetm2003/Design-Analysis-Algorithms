//You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?
// Note: Given n will be a positive integer.

// Example 1:
// Input: 2
// Output: 2

// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

#include<iostream>
using namespace std;

class cs{
    public:

    int cliambstairs(int n)
    {
        int pre = 1;
        int curr = 1;
        int temp = 0;

        for(int i = 1; i < n; i++){
            temp = curr;
            curr = curr + pre;
            pre = temp;
            //cout<<curr<<endl;
        }
        return curr;
    }
};

int main(){
    cs c;
    int p = 0;
    p = c.cliambstairs(5);
    cout<<p<<endl;
}

// time complexity : O(n)
// space complexity : O(1)