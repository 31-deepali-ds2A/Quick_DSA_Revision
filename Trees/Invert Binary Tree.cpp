
#include <iostream>  
#include <algorithm> 
#include <queue>    

using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        
        root->left=right;
        root->right=left;
        return root;
    }
};

// itervative(BFS)-> O(n) & )(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                swap(node->left,node->right); // swap 
            }
        }
        return root;
    }
};