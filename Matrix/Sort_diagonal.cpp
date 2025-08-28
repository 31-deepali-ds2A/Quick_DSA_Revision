// You are given an n x n square matrix of integers grid. Return the matrix such that:

// The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
// The diagonals in the top-right triangle are sorted in non-decreasing order.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n<=1) return grid;
        int row,col;
        vector<vector<int>> res=grid;

        for(int i=0;i<n;i++){
            vector<int> diag;
            row=i,col=0;
            while(row<n && col<n){
                diag.push_back(grid[row][col]);
                row++; col++;
            }
            sort(diag.begin(),diag.end(),greater<int>());
            row=i,col=0;
            for(int k=0;k<diag.size();k++){
                res[row][col]=diag[k];
                row++; col++;
            }
        }

        for(int j=1;j<n;j++){
            vector<int> diag;
            row=0,col=j;
            while(row<n && col<n){
                diag.push_back(grid[row][col]);
                row++; col++;
            }
            sort(diag.begin(),diag.end());
            row=0, col=j;
            for(int k=0;k<diag.size();k++){
                res[row][col]=diag[k];
                row++;
                col++;
            }
        }
        
        return res;
    }
};