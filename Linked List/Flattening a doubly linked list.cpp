
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;

        Node* curr=head;
        
        while(curr!=nullptr){
            
            // found valid child
            if(curr->child){
                Node* fow=curr->next;
                curr->next=flatten(curr->child);
                curr->next->prev=curr;
                curr->child=nullptr;

                // find tail
                while(curr->next!=nullptr){
                    curr=curr->next;
                }
                // connect tail to fow ptr
                if(fow!=nullptr){
                    curr->next=fow;
                    fow->prev=curr;
                }
            }
            curr=curr->next;
        }
        return head;
    }
};