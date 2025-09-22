#include <iostream>  
#include <algorithm> 
#include <queue>    

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

// O(n) + space O(1) 
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // morris inorder traversal
        Node* curr=root;
        vector<int> inorder;
        while(curr!=nullptr){
            if(!curr->left){
                inorder.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->data);
                    curr=curr->right;
                }
            }
            
        }
        return inorder;
    }
};

// pre-order
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // morris preorder traversal
        Node* curr=root;
        vector<int> preorder;
        while(curr!=nullptr){
            if(!curr->left){
                preorder.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    preorder.push_back(curr->data); // chnge this only
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                   // inorder.push_back(curr->data);
                    curr=curr->right;
                }
            }
            
        }
        return preorder;
    }
};