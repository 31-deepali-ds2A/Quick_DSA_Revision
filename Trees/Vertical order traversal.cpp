#include <iostream>  
#include <algorithm> 
#include <vector> 
#include<set>  
#include<map>
#include<tuple>
#include<queue> 

using namespace std;
  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // multiset is used-> it maintains sorted order , insertion take O(log k) each
        
        map<int,map<int,multiset<int>>> mp; 
        queue<tuple<TreeNode*,int,int>> q; //node,row,col
        q.push({root,0,0});

        while(!q.empty()){
            auto[node,row,col]=q.front();
            q.pop();
            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left,row+1,col-1});
            }
            if(node->right){
                q.push({node->right,row+1,col+1});
            }
        }
        vector<vector<int>> res;
        for(auto& [col,rows]:mp){
           vector<int> column;
            for (auto &[row, vals] : rows) {
            column.insert(column.end(), vals.begin(), vals.end());
            }
            res.push_back(column);
        }
        return res;
    }
};