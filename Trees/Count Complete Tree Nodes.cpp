
 // Definition for a binary tree node.
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 // brute force--------------------------
 // using dfs-> O(n)


//--------------------------------------------------------------------------------------

 // optimal O((log n)^2)
 // approach:
 
//  For each subtree:
// Compute left height (go left until NULL).
// Compute right height (go right until NULL).

// If leftHeight == rightHeight:

// It’s a perfect tree → return 2^(height+1) - 1.

// Else:
// Recursively count left and right children.




class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh=leftH(root);
        int rh=rightH(root);

        if(lh==rh){
            return (1<<lh)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
private:
    int leftH(TreeNode* root){
        int h=0;
        while(root!=nullptr){
            h++;
            root=root->left;
        }
        return h;
    }

    int rightH(TreeNode* root){
        int h=0;
        while(root!=nullptr){
            h++;
            root=root->right;
        }
        return h;
    }
};