// Tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

// Should return true if tree is Sum Tree, else false
// O(n^2) & O(h)
class Solution {
  public:
    bool isSumTree(Node* root) {
        // Your code here
    if (root == nullptr ||(root->left == nullptr &&root->right==nullptr))
        return true;
        int s1, s2;
         s1=sum(root->left);
         s2=sum(root->right);
        
         if ((root->data == s1 + s2) &&isSumTree(root->left) &&
                   isSumTree(root->right))
        return true;
    return false;
    }
    
    int sum(Node* root){
        int s=0;
        if(!root) return 0;
        s+=root->data;
        if(root->left){
            
            root=root->left;
        }
        else{
            root=root->right;
        }
        return s;
    }
 
};

//O(n) & O(h)

class Solution {
  public:
    bool isSumTree(Node* root) {
        // Your code here
        int t=isSum(root);
        return t!=-1;
        
    }
    
    int isSum(Node* root) {
    
    if(root == nullptr)
        return 0;
    
    // If node is leaf node, return its value.    
    if (root->left == nullptr && root->right == nullptr)
        return root->data;
    
    // Calculate left subtree sum
    int ls = isSum(root->left);
    
    // if left subtree is not sum tree,
    if(ls == -1)
        return -1;
    
    // Calculate right subtree sum
    int rs = isSum(root->right);
    
    // if right subtree is not sum tree,
    if(rs == -1)            
        return -1;
    
    
    if(ls + rs == root->data)
        return ls + rs + root->data;
    else
        return -1;
 
}
    
};