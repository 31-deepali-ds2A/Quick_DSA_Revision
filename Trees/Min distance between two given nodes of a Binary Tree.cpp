// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        
        Node* node=LCA(root,a,b);
        int d1=findLevel(node,a,0);
        int d2=findLevel(node,b,0);
        
        return d1+d2;
        
       
    }
    
    Node* LCA(Node* root,int a,int b){
        if(root==nullptr || root->data==a || root->data==b){
            return root;
        }
        
        Node* left=LCA(root->left,a,b);
        Node* right=LCA(root->right,a,b);
        
        if(left==nullptr) return right;
        if(right==nullptr) return left;
        else return root;
    }

     // now find dis of node to a & b and return
    int findLevel(Node* root, int target, int level) {
        if (!root) return -1;
        if (root->data == target) return level;

        int left = findLevel(root->left, target, level + 1);
        if (left != -1) return left; // If found in left subtree, return

        return findLevel(root->right, target, level + 1);
    }
};