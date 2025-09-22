#include <iostream>  
#include <algorithm> 
#include <stack> 
#include<vector>   

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // O(N * distance²)
class Solution {
    int pairs=0;
public:
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return pairs;
    }

    vector<int> dfs(TreeNode* root,int distance){
        vector<int> count(distance+1,0);

        if(!root) return count;
        if(!root->left && !root->right){
            count[1]=1;
            return count;
        }

        vector<int> left_dist=dfs(root->left,distance);
        vector<int> right_dist=dfs(root->right,distance);

        for (int i=1;i<=distance;i++) {
            for (int j=1;j<=distance-i;j++) {
               pairs+=left_dist[i]*right_dist[j];
            }
        }
       
       // shoft dist for parents 
        for (int i=1;i<distance;i++)
           count[i+1]=left_dist[i]+right_dist[i];

        return count;

    }
};

// O(N * k²)
class Solution {
    int pairs=0;
public:
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return pairs;
    }
    vector<int> dfs(TreeNode* root,int distance){
        if(!root) return {};
        if(!root->left && !root->right) return {1};

        vector<int> left_dist=dfs(root->left,distance);
        vector<int> right_dist=dfs(root->right,distance);

        for (int l : left_dist) {
            for (int r : right_dist) {
                if (l + r <= distance) {
                    pairs++;
                }
            }
        }

         vector<int> all_dist;
        for (int d : left_dist)
            if (d + 1 <= distance) all_dist.push_back(d + 1);
        for (int d : right_dist)
            if (d + 1 <= distance) all_dist.push_back(d + 1);
            
        return all_dist;

    }
};