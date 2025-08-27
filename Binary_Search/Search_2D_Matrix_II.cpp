#include <vector>
using namespace std;

/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix.
This matrix has the following properties:

1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.

Example:
Input: 
matrix = [
  [1,4,7,11,15],
  [2,5,8,12,19],
  [3,6,9,16,22],
  [10,13,14,17,24],
  [18,21,23,26,30]
], target = 5
Output: true

Input: 
matrix = [
  [1,4,7,11,15],
  [2,5,8,12,19],
  [3,6,9,16,22],
  [10,13,14,17,24],
  [18,21,23,26,30]
], target = 20
Output: false
*/

// ===============================
// Brute Force 1 - Check Each Element
// ===============================
class SolutionBruteForce1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Check each element
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};

// ===============================
// Brute Force 2 - Binary Search in Each Row
// ===============================
class SolutionBruteForce2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Perform binary search in each row
        for(int i = 0; i < n; i++){
            int left = 0;
            int right = m - 1;

            while(left <= right){
                int mid = left + (right - left) / 2;

                if(matrix[i][mid] == target){
                    return true;
                }
                else if(matrix[i][mid] < target){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

// ===============================
// Optimized Approach - Start from Top Right
// ===============================
class SolutionOptimized {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = m - 1; // Start from top-right
        while(i < n && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] < target){
                i++; // Move down
            }
            else{
                j--; // Move left
            }
        }
        return false;
    }
};

