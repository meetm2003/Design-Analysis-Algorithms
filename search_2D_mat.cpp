// Search 2D matrix using Divide and conqure

// input : {{1, 4, 7, 11},{2, 5, 8, 12},{3, 6, 9, 16},{10, 13, 14, 17}}, target 5
// output : true

// input : {{1, 4, 7, 11},{2, 5, 8, 12},{3, 6, 9, 16},{10, 13, 14, 17}}, target 20
// output : true

// Time complexity : O(m+n)
// space complexity : O(1)

#include <iostream>
using namespace std;
#include <vector>

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //vector<vector<int>>& matrix is for making 2D array...
    int no_of_row = matrix.size(); // That variable gives nunber of rows...
    if (no_of_row == 0) {
        return false;
    }
    
    int no_of_column = matrix[0].size(); // That variable gives nunber of column...
    int r = 0;
    int c = no_of_column - 1;
    int count = 0;
    
    while (r < no_of_row && c >= 0) {
        if (target > matrix[r][c]) { 
            // Searching start from right most element, because it gives elimination and efficiency...
            r++;
        } else if (target < matrix[r][c]) {
            c--;
        } else {
            cout<<count<<endl;
            return true;
        }
        count++;
    }
    return false;
}


int main() {
    // Example usage:
    std::vector<std::vector<int>> matrix = {{1, 4, 7, 11},
                                            {2, 5, 8, 12},
                                            {3, 6, 9, 16},
                                            {10, 13, 14, 17}};
    int target = 9;
    
    if (searchMatrix(matrix, target)) {
        std::cout << "Target found in the matrix." << std::endl;
    } else {
        std::cout << "Target not found in the matrix." << std::endl;
    }
    
    return 0;
}
