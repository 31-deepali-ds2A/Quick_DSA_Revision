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


// approach1-> O(n) =Where h = height of the BST (≈ O(log n) for a balanced tree) & O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){

        if(p->val> root->val && q->val> root->val){
           root=root->right;
        }
        else if(p->val<root->val && q->val<root->val){
           root=root->left;
        }
        else{
            return root;
        }
       
        }
         return nullptr;
    }
};

// approach2-> O(h) & O(h)stack depth

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(p->val> root->val && q->val> root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else{
            return root;
        }
    }
};