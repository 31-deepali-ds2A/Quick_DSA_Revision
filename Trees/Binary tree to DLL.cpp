#include <iostream>  
#include <algorithm> 
#include <queue>    

using namespace std;

// Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 

// using morris inorder traversal
class Solution {
  public:
    Node* bToDLL(Node* root) {
        // code here
        if(!root) return nullptr;
        
        Node* curr=root;
        Node* head=nullptr;
        Node* prev=nullptr;
        
        while(curr!=nullptr){
            if(!curr->left){
                // link to dll
                if(!head) head=curr;
                curr->left=prev;
                if(prev) prev->right=curr;
                prev=curr;
                
                curr=curr->right;
            }
            else{
                Node* pre=curr->left;
                while(pre->right && pre->right!=curr){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right=curr;
                    curr=curr->left;
                }
                else{
                    pre->right=nullptr;
                    
                    //link to dll
                    if(!head) head=curr;
                    curr->left=prev;
                    if(prev) prev->right=curr;
                    prev=curr;
                    
                    curr=curr->right;
                }
            }
        }
        return head;
    }
};