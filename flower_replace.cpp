// flower place problem...

// Suppose you have a long flowerbed in which some of the plots are planted and some are not.
// However, flowers cannot be planted in adjacent plots - they would compete for water 
//and both would die.

// Given a flowerbed (represented as an array containing 0 and 1, 
//where 0 means empty and 1 means not empty), and a number n, 
//return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: True
// Example 2:
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: False

//content from www.igotanoffer.com

#include<iostream>
using namespace std;

class solution{
    public:
        bool canplaceFlower(int a[],int size, int n){ 
            if(size == 0 || n > size / 2 + 1) return false;
            int count = 0;
            for(int i = 0; size && count < n; i++){
                if(a[i] == 0){
                    int prev = i == 0 ? 0 : a[i - 1];
                    int next = i == size ? 0 : a[i + 1];
                    if(prev == 0 && next == 0){
                        a[i] = 1;
                        count++;
                    }
                }
            }
            return count == n;
        }
};
int main(){
    solution s;
    int a[100] = {0};
    int size = sizeof(a) / sizeof(a[0]);
    cout<< s.canplaceFlower(a,size,51)<<endl;
}
