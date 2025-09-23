#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        if(!root) return {};
        vector<int> ans;
        
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            // push in map the latest
            mp[it.second]=it.first->data;
            
            // move left and -1 idx
            if(it.first->left){
                q.push({it.first->left,it.second-1});
            }
            
            // move right and +1 idx
            if(it.first->right){
                q.push({it.first->right,it.second+1});
            }
            
        }
        for(auto& it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};