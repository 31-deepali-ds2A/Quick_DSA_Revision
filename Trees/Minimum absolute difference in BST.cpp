#include <iostream>  
#include <algorithm> 
#include <stack> 
#include<vector>   

using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// approach 1

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);

        int minDiff=INT_MAX;
        for(int i=1;i<ans.size();i++){
            minDiff=min(minDiff,ans[i]-ans[i-1]);
        }
        return minDiff;
    }
    vector<int> inorder(TreeNode* root,vector<int>& ans){
        if(!root) return {};
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

        return ans;
    }
};

// approach 2

class Solution {
    int minDiff = INT_MAX;
    int prev = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
    void inorder(TreeNode* root){
        if(!root) return ;

        inorder(root->left);

        if(prev!=-1){
            minDiff=min(minDiff,root->val-prev);
        }
        prev=root->val;
        inorder(root->right);

        return ;
    }
};

// approach 3

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr=root;
        int prev=-1,minDiff=INT_MAX;

        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top(); st.pop();
            if(prev!=-1) minDiff=min(minDiff,curr->val-prev);
            prev=curr->val;
            curr=curr->right;
        }
        return minDiff;
    }
};