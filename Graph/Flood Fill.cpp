class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
       
        vector<vector<int>> mat=image;
        int initialColor=image[sr][sc];
        
        dfs(sr,sc,mat,image,initialColor,newColor);
        return mat;
    }
    
    void dfs(int row,int col,vector<vector<int>>& mat,vector<vector<int>> &image,
    int initialColor,int newcolor){
        
        mat[row][col]=newcolor;
        
        int n=mat.size(); int m=mat[0].size();
        
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        
        for(int k=0;k<4;k++){
            int nr=delr[k]+row;
            int nc=delc[k]+col;
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==initialColor 
            && mat[nr][nc]!=newcolor){
                dfs(nr,nc,mat,image,initialColor,newcolor);
            }
        }
        return ;
        
    }
};