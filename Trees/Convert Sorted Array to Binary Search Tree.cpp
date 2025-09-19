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


// 

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums,0,nums.size()-1);
    }
    TreeNode* buildBST(vector<int>& nums,int start,int end){
        if(start>end) return nullptr;
        int mid=start+(end-start)/2;

        TreeNode* node=new TreeNode(nums[mid]);
        node->left=buildBST(nums,start,mid-1);
        node->right=buildBST(nums,mid+1,end);

        return node;
    }

};