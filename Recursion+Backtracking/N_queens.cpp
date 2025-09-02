// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens
// ' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));


        //tracking sets
        vector<bool> cols(n,false),diag1(2*n,false),diag2(2*n,false);
        canPlace(0,n,board,ans,cols,diag1,diag2);
        return ans;
    }

    void canPlace(int row,int n,vector<string>& board,vector<vector<string>>& ans,vector<bool>& cols,vector<bool>& diag1,vector<bool>& diag2){

        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(cols[col] || diag1[row-col+n] || diag2[row+col]) continue;

            board[row][col]='Q';
            cols[col]=diag1[row-col+n]=diag2[row+col]=true;

            canPlace(row+1,n,board,ans,cols,diag1,diag2);
            board[row][col]='.';
            cols[col]=diag1[row-col+n]=diag2[row+col]=false;
        }
    }
};