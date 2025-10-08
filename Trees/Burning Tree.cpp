/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        if(!root) return 0;
        unordered_map<Node*,Node*> mp;
        Node* targetNode=findParentPointer(root,target,mp);
        
        if(!targetNode) return -1;
        unordered_map<Node*,bool> vis;
        queue<pair<Node*,int>> q; // node,time
        // start from target
        q.push({targetNode,0});
        vis[targetNode]=true;
        int maxTime=0;
        
        while(!q.empty()){
            auto&[node,time]=q.front();
            q.pop();
            
            maxTime=max(maxTime,time);
            if(node->left && !vis[node->left]){
                q.push({node->left,time+1});
                vis[node->left]=true;
            }
            
            if(node->right && !vis[node->right]){
                q.push({node->right,time+1});
                vis[node->right]=true;
            }
            
            // Spread the fire to the parent
            if(mp.find(node)!=mp.end() && !vis[mp[node]]){
                q.push({mp[node],time+1});
                vis[mp[node]]=true;
            }
        }
        return maxTime;
        
    }
    
    Node* findParentPointer(Node* root,int target,unordered_map<Node*,Node*>& mp){
        Node* targetnode=nullptr;
        queue<Node*> q;
        q.push(root);
        
        // find parents node for each except root
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            
            if(node->data==target){
                targetnode=node;
            }
            if(node->left){
                q.push(node->left);
                mp[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right]=node;
            }
        }
        return targetnode;
    }
};