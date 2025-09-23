#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// Use a hash map:

// Key = serialized string of subtree
// Value = count of how many times we’ve seen this subtree
// Whenever a signature’s count becomes 2 (not 1), we’ve found a duplicate → add the current 
// node to the result.

class Solution {
    unordered_map<string,int> mp;
    vector<TreeNode*> res;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return res;
        dfs(root);
        return res;
    }
    string dfs(TreeNode* root){
        if(!root) return "#";
        string left=dfs(root->left);
        string right=dfs(root->right);

        string serial=to_string(root->val)+","+left+","+right;

        if(++mp[serial]==2) res.push_back(root);
        return serial;
    }
};