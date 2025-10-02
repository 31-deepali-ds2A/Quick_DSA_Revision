#include<unordered_map>
#include<algorithm>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*,Node*> mp;
        Node* curr=head;

        while(curr!=nullptr){
            mp[curr]=new Node(curr->val);
            curr=curr->next;
        }
       curr=head;

        while(curr){
           mp[curr]->next=mp[curr->next];
           mp[curr]->random=mp[curr->random];
           curr=curr->next;
        }
        return mp[head];
    }
};

// optimal
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* curr=head;

        // insert clone nodes after each original node
        while(curr){
            Node* newNode=new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
        }

       // assign random pointers to clones
       curr=head;
       while(curr){
        if(curr->random){
            curr->next->random=curr->random->next;

        }
        curr=curr->next->next; // skip clone
       }

       // separate original & clone
       curr=head;
       Node* copyHead=head->next;
       Node* copyCurr=copyHead;

       while(curr){
        curr->next=curr->next->next;
        if(copyCurr->next){
            copyCurr->next=copyCurr->next->next;
        }
        curr=curr->next;
        copyCurr=copyCurr->next;
       }
       return copyHead;
    }
};