// DFS each unvisited node, marking its parent; if a visited neighbor is found that is not the parent, 
// a cycle exists. Repeat for all disconnected components.

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) { // edges is an edge list not adj list
        // Code here
         vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);  
             adj[e[1]].push_back(e[0]);
        }
        
        int vis[V]={0};
       
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,-1)) return true;
            }
        }
        return false;
    }
    
    private:
        bool dfs(int node,vector<vector<int>>& adj,int vis[],int parent){
            vis[node]=1;
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    if(dfs(it,adj,vis,node)) return true;
                }
                else if(it!=parent){ // vis & on same path
                    return true;
                }
            }
           
            return false;
        }
};