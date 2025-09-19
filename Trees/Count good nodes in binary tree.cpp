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

//recusrive

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return DFS(root,INT_MIN);
    }
    int DFS(TreeNode* root, int maxsofar){
        if(!root) return 0;
        int good=0;
        
        if(root->val >=maxsofar){
            good=1;
            maxsofar=root->val;
        }

        return good+DFS(root->left,maxsofar)+DFS(root->right,maxsofar);
    }
};

// iterative
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val}); 

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto[ node,maxi]=q.front();
                q.pop();
                if(node->val >= maxi) count++;
                int newmax=max(maxi,node->val);

                if(node->left ){
                    q.push({node->left,newmax});
                }
                if(node->right ){
                    q.push({node->right,newmax});
                }
            }
        }
        return count;
    }
};