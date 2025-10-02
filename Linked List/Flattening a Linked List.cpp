#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// brute force
class Solution {
  public:
    Node* formll(vector<int>& arr){
        Node* dummyNode=new Node(-1);
        Node* temp=dummyNode;
        
        for(int i=0;i<arr.size();i++){
            temp->bottom=new Node(arr[i]);
            temp=temp->bottom;
        }
        return dummyNode->bottom;
    }
    
    
    Node *flatten(Node *root) {
        // code here
        vector<int> arr;
        while(root!=nullptr){
            Node* t2=root;
            while(t2!=nullptr){
            arr.push_back(t2->data);
            
            t2=t2->bottom;
            }
            root=root->next;
        }
        sort(arr.begin(),arr.end());
        return formll(arr);
    }
};

// optimal 
class Solution {
  public:
    Node* merge(Node* list1, Node* list2){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        
        while(list1!=nullptr && list2!=nullptr){
            if(list1->data < list2->data){
                res->bottom=list1;
                res=list1;
                list1=list1->bottom;
            }
            else{
                res->bottom=list2;
                res=list2;
                list2=list2->bottom;
            }
            res->next=nullptr;
        }
        
        if(list1){
            res->bottom=list1;
        }
        else{
            res->bottom=list2;
        }
        
        // break the last node-> prevent cycle
        if(dummyNode->bottom){
            dummyNode->bottom->next=nullptr;
        }
        return dummyNode->bottom;
    }
    
    
    Node *flatten(Node *root) {
        if(root==nullptr || root->next==nullptr){
            return root;
        }
        Node* mergedHead=flatten(root->next);
        root=merge(root,mergedHead);
        return root;
    }
};