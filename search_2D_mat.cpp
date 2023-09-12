// Search 2D matrix using Divide and conqure

// input : {{1, 4, 7, 11},{2, 5, 8, 12},{3, 6, 9, 16},{10, 13, 14, 17}}, target 5
// output : true

// input : {{1, 4, 7, 11},{2, 5, 8, 12},{3, 6, 9, 16},{10, 13, 14, 17}}, target 
// output : false

// Time complexity : O(log(m*n))
// Space complexity : O(log(m*n))

#include <iostream>
using namespace std;
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target, int left, int top, int right, int bottom) {
    if (left > right || top > bottom) {
        return false;
    }

    int midRow = (top + bottom) / 2;
    int midCol = (left + right) / 2;

    if (matrix[midRow][midCol] == target) {
        return true;
    } else if (matrix[midRow][midCol] > target) {
        // The target may be in the top-left or bottom-left submatrix.
        return searchMatrix(matrix, target, left, top, midCol - 1, bottom) ||
               searchMatrix(matrix, target, left, top, right, midRow - 1);
    } else {
        // The target may be in the top-right or bottom-right submatrix.
        return searchMatrix(matrix, target, midCol + 1, top, right, bottom) ||
               searchMatrix(matrix, target, left, midRow + 1, right, bottom);
    }
}

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) {
        return false;
    }

    int n = matrix[0].size();
    return searchMatrix(matrix, target, 0, 0, n - 1, m - 1);
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

// this function is not using divide & conquer...
// it gives simple idea...

// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     //vector<vector<int>>& matrix is for making 2D array...
//     int no_of_row = matrix.size(); // That variable gives nunber of rows...
//     if (no_of_row == 0) {
//         return false;
//     }
    
//     int no_of_column = matrix[0].size(); // That variable gives nunber of column...
//     int r = 0;
//     int c = no_of_column - 1;
//     int count = 0;
    
//     while (r < no_of_row && c >= 0) {
//         if (target > matrix[r][c]) { 
//             // Searching start from right most element, because it gives elimination and efficiency...
//             r++;
//         } else if (target < matrix[r][c]) {
//             c--;
//         } else {
//             cout<<count<<endl;
//             return true;
//         }
//         count++;
//     }
//     return false;
// }
