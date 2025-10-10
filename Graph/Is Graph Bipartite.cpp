// A graph is bipartite if it contains a odd cycle
// & it we can color all nodes with two different color such that no 2 adjecent nodes have same color

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
            if(dfs(graph,vis,0,i)==false) return false;} // if any nodes return false
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& graph,vector<int>& vis,int col,int node){
        vis[node]=col;

        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(dfs(graph,vis,!col,it)==false) return false; // if any nodes return false
            }
            else if(vis[it]==col){
                return false;
            }
        }
        return true;
    }
};