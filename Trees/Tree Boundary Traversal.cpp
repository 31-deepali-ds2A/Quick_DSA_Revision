#include<iostream>
#include<vector>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code he
        vector<int> res;
        
        if(!root) return res;
        if(!isleaf(root)) res.push_back(root->data);
        
        addleftboundary(root,res);
        addleaf(root,res);
        addrightboundary(root,res);
        
        return res;
    }
    private:
    // to check leaf node
        bool isleaf(Node* root){
            if(!root->left && !root->right) return true;
            return false;
        }
        
        // to add left boundaries only
        void addleftboundary(Node* root,vector<int>& res){
            Node* curr=root->left;
            while(curr){
                if(!isleaf(curr)){
                    res.push_back(curr->data);
                }
                if(curr->left){
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }
        }

        // to add right boundaries only
        void addrightboundary(Node* root,vector<int>& res){
            Node* curr=root->right;
            vector<int> temp;
            while(curr){
                if(!isleaf(curr)){
                    temp.push_back(curr->data);
                }
                if(curr->right){
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
                
            }
            for (int i = temp.size() - 1; i >= 0; --i) {
                    res.push_back(temp[i]);
            }
        }
        
        // to add leaf nodes
        void addleaf(Node* root,vector<int>& res){
            if(isleaf(root)){
                res.push_back(root->data);
                return;
            }
            if(root->left){
                addleaf(root->left,res);
            }
            if(root->right){
                addleaf(root->right,res);
            }
        }
};