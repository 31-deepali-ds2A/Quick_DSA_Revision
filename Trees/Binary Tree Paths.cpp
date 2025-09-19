
#include <iostream>  
#include <algorithm> 
#include <queue> 
#include<stack>
#include<string>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return {};
        string temp="";
         path(root,ans,temp);
         return ans;
    }

    void path(TreeNode* root,vector<string>& ans,string temp){
        if(!root) return;

        temp += to_string(root->val); 

        if(!root->left && !root->right) {
            ans.push_back(temp);
            return;
            
        }
        
        temp+="->";

        path(root->left,ans,temp);
        path(root->right,ans,temp);

        return ;
    }
};


// iterative
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        stack<pair<TreeNode*, string>> st;
        st.push({root, to_string(root->val)});

        while (!st.empty()) {
            auto [node, path] = st.top();
            st.pop();

            if (!node->left && !node->right)
                ans.push_back(path);

            if (node->right)
                st.push({node->right, path + "->" + to_string(node->right->val)});
            if (node->left)
                st.push({node->left, path + "->" + to_string(node->left->val)});
        }
        return ans;
    }
};
