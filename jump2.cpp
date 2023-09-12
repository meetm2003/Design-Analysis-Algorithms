//jump problem...
//Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Input: nums = [2,3,0,1,4]
// Output: 2

//time complexity :: O(n)
//space complexity :: O(1)

#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
        int jump(vector<int>& nums){
            int jump = 0;
            int current = 0;
            int farther = 0;
            for(int i = 0; i < nums.size() - 1; i++){
                farther = max(farther, nums[i]+i);
                if(i == current){
                    current = farther;
                    jump++;
                }
            }
        return jump;
        }
};
int main(){
    solution s;
    vector<int> nums = {2,3,1,1,6};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout<<s.jump(nums)<<endl;
}