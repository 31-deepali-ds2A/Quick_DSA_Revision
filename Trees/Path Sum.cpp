#include <iostream>  
#include <algorithm> 
#include <queue>    

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
 


// bfs
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        queue<pair<TreeNode*, int>> q;
        q.push({root, targetSum - root->val});

        while (!q.empty()) {
            auto [node, rem] = q.front();
            q.pop();

            if (!node->left && !node->right && rem == 0) return true;

            if (node->left)
                q.push({node->left, rem - node->left->val});
            if (node->right)
                q.push({node->right, rem - node->right->val});
        }
        return false;
    }
};

// recusrive
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
    }
    bool helper(TreeNode* root,int target){
        if(!root) return false;
        if(root->left==nullptr && root->right==nullptr && target==root->val)
            return true;

        return helper(root->left,target-root->val)||
        helper(root->right,target-root->val);
    }
    
};