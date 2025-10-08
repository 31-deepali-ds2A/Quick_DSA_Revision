class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0)), 
        dis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[row][col]=steps;
            
              for(int k=0;k<4;k++){
           int nr=delr[k]+row;
           int nc=delc[k]+col;
           
           if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
               vis[nr][nc]=1;
               q.push({{nr,nc},steps+1});
           }
            
        }
        }
        return dis;
      
    }
};