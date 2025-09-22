#include <iostream>  
#include <algorithm> 
#include <queue>    

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  // using morris pre-order
  
class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        TreeNode* curr=root;

        while(curr){
            if(curr->left){
                // find rightmost
                TreeNode* pre=curr->left;
                while(pre->right){
                    pre=pre->right;
                }
                // connect
                pre->right=curr->right;//
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};