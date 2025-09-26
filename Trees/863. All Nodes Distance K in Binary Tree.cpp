#include<unordered_map>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        findParents(root,target,mp);
        
        unordered_set<TreeNode*> vis; // we can also use unordered_map for visited
        vis.insert(target);
        vector<int> res;

        queue<pair<TreeNode*,int>>q;
        q.push({target,0});

        while(!q.empty()){
            auto[node,dis]=q.front();
            q.pop();
            if(dis==k) res.push_back(node->val);

            if(node->left && vis.find(node->left)==vis.end()){
                vis.insert(node->left);
                q.push({node->left,dis+1});
            }

            if(node->right && vis.find(node->right)==vis.end()){
                vis.insert(node->right);
                q.push({node->right,dis+1});
            }
            if(mp[node] && vis.find(mp[node])==vis.end()){
                vis.insert(mp[node]);
                q.push({mp[node],dis+1});
            }
        }
        return res;
    }

    void findParents(TreeNode* root,TreeNode* target,   unordered_map<TreeNode*,TreeNode*>& mp){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                mp[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right]=node;
            }
        }
        return ; // as target pointer is already given no need to find the pointer again
    }
};