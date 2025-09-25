#include <iostream>  
#include <algorithm> 
#include <vector> 
#include<set>  
#include<map>
#include<numeric>

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


// O(n^2)
class Solution {
    int maxSum=0;
public:
    int maxSumBST(TreeNode* root) {
       helper(root);
        return maxSum;
    }
      void helper(TreeNode* root) {
        if (!root) return;

        int sum = isValid(root);
        maxSum = max(maxSum, sum);

        // Recursively check all subtrees
        helper(root->left);
        helper(root->right);
    }
    
    int isValid(TreeNode* root){
        vector<int> res;
        inorder(root,res);

       for(int i=1;i<res.size();i++){
            if(res[i-1]>=res[i])
                return 0;
       }
        return accumulate(res.begin(),res.end(),0);
    }

    void inorder(TreeNode* root,vector<int>& res){
        if(!root) return ;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
};