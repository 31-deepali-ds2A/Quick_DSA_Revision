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

// recusrive
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSameTree(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) || 
            isSubtree(root->right,subRoot);
    }

    bool isSameTree(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || ! subRoot) return false;
        if(root->val != subRoot->val) return false;

        return isSameTree(root->left,subRoot->left) &&
         isSameTree(root->right,subRoot->right);
    }
};

//iterative



class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (!subRoot) return true; // empty tree is always a subtree

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == subRoot->val && isSameTreeIter(curr, subRoot))
                return true;

            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        return false;
    }

private:
    bool isSameTreeIter(TreeNode* a, TreeNode* b) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({a, b});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (!x && !y) continue;
            if (!x || !y) return false;
            if (x->val != y->val) return false;

            q.push({x->left,  y->left});
            q.push({x->right, y->right});
        }
        return true;
    }
};
