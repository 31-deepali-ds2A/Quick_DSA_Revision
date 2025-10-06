#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
    
        int n=adj.size();
        
        int vis[n]={0};
        int start=0;
        
        vector<int> ans;
        
        dfs(start,adj,ans,vis);
        
        return ans;
    }
    
    void dfs(int node,vector<vector<int>>& adj,vector<int>& ans,int vis[]){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,ans,vis);
            }
        }
    }
};