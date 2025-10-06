#include<vector>
#include<queue>
using namespace std;

// bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }

    void bfs(int row,int col, vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n=grid.size() , m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

              // Only 4 directions: up, right, down, left
                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, 1, 0, -1};

            // traverse neighbours
                for(int k=0;k<4;k++){
                    int nrow= r+drow[k];
                    int ncol= c+dcol[k];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    
};

// dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int row,int col, vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n=grid.size() , m=grid[0].size();
        vis[row][col]=1;

        // Only 4 directions: up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

            // traverse neighbours
                for(int k=0;k<4;k++){
                    int nrow= row+drow[k];
                    int ncol= col+dcol[k];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        dfs(nrow,ncol,vis,grid);
                    }
                }
        }
    
};