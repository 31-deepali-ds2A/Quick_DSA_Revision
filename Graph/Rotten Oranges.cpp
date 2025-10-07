class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cntFresh=0;
        queue<pair<pair<int,int>,int>> q; // row,col,time

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==0){
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
        
        int time=0;
        int cnt=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(t,time);
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+delr[k];
                int nc=c+delc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=1
                 && grid[nr][nc]==1){
                        q.push({{nr,nc},time+1});
                        vis[nr][nc]=1;
                        cnt++;
                }
            }
        }

        return cnt!=cntFresh?-1:time;
    }
       
    
};