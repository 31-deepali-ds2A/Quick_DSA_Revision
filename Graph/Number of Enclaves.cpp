class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        // boundary cells
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                q.push({0,j});
                vis[0][j]=1;
            }

            if(grid[n-1][j]==1 && !vis[n-1][j]){
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        int land=0;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=delr[k]+r;
                int nc=delc[k]+c;

                if(nr>=0 && nr< n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        // counting unvisited land
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    land++;
                }
            }
        }
        return land;
    }
};