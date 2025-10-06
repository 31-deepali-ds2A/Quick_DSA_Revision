#include<vector>
#include<queue>
using namespace std;


// dfs
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        // cover boundaries
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,board);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,board);
            }
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,vis,board);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,vis,board);
            }
        }

        // mark unvisted node -> 'X'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
        return ;
    }

    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int n=board.size(), m=board[0].size();

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nr=delrow[k]+row;
            int nc=delcol[k]+col;

            if(nr>=0 && nr<n && nc>=0 && nc<m &&
             !vis[nr][nc] && board[nr][nc]=='O'){
            
                dfs(nr,nc,vis,board);
            }
        }
        return ;
    }
};