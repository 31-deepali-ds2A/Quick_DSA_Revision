class Solution {
private:
    void dfs(int node,vector<int>& vis,vector<int> adjLs[]){
        vis[node]=1;
        for(auto it:adjLs[node]){
            if(!vis[it]){
                dfs(it,vis,adjLs);
            }
        }
        return ;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adjLs[n];
        vector<int> vis(n);

//      adj mat-> adj ls
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjLs);
            }
        }
        return cnt;
    }
};