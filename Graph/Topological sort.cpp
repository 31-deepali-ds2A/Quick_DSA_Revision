// Always performed only in Directed Acyclic Graph (DAG).
// It is a Linear ordering of vertices such that if there is an edge between u & v then u must appear
// before v in that ordering.


// using DFS
class Solution {
    private:
        void dfs(int node,int vis[],stack<int> &st,vector<int> adj[]){
            vis[node]=1;
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    dfs(it,vis,st,adj);
                }
            }
            st.push(node);
        }
        
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        
              for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
                
        stack<int> st;
        int vis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        return ans;
    }
};