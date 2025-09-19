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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return depth(root, 0);
    }

    int depth(TreeNode* root, int d) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int l = 0, r = 0;
        l = depth(root->left, d);
        r = depth(root->right, d);

        d = max(l, r) + 1;
        return d;
    }
};



//iterative(using BFS)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q; int depth=0;
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
            }
            depth++;
        }
        return depth;
    }
};