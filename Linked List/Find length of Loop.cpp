
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
        Node* fast=head;
       
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                Node* temp=slow->next;
                int count=1;
                
                while(temp!=slow){
                    count++;
                    temp=temp->next;
                }
                return count;
            } 
        }
       
        
        return 0;
    }
};