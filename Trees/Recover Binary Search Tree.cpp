#include <iostream>  
#include <algorithm> 
#include <vector>    

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
 

  // takes O(n) extra space--------------------------------------------------------------------
class Solution {
    vector<int> res;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int> temp(res.begin(),res.end());
        sort(temp.begin(),temp.end());
        if(temp==res) return;

       int first=-1,second=-1;
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=res[i]){
               if(first==-1) first=res[i];
               else second=res[i];
            }
        }
        fix(root,first,second);
    }

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);

        return;
    }

    void fix(TreeNode* root,int x,int y){
        if(!root) return;
        if(root->val==x) root->val=y;
        else if(root->val==y) root->val=x;
        fix(root->left,x,y);
        fix(root->right,x,y);
    }

};

// O(h) stack space-----------------------------------------------------------------------------
class Solution {
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
    TreeNode* prev=new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);

        if(prev->val > root->val){
            if(!first) first=prev;
            second=root;
        }
        prev=root;
        inorder(root->right);
    }

};

// using morris O(1)--------------------------------------------------------------------------
class Solution {
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
    TreeNode* pre=nullptr;
public:
    void recoverTree(TreeNode* root) {
       TreeNode* curr=root;

       while(curr){
        if(!curr->left){
            if(pre && pre->val > curr->val){
                if(!first) first=pre;
                 second=curr;
            }
            pre=curr;
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==nullptr){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=nullptr;
                if (pre && pre->val > curr->val) {
                        if (!first) first = pre;
                        second = curr;
                    }
                pre=curr;
                curr=curr->right;
            }
        }
       }
        swap(first->val,second->val);
    }

};
