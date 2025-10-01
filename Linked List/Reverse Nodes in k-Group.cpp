#include<vector>
using namespace std;

// ll defintion
struct ListNode {
     int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


  class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        int count=0;

        ListNode* curr=head;
        while(curr!=nullptr && count<k){
            curr=curr->next;
            count++;
        }

// if count is less than k return head immeditaely
        if(count<k) return head;

          // reverse first k nodes
        curr=head;
        ListNode* prev=nullptr;
        ListNode* fow=nullptr;
        count=0;
        
        while(curr!=nullptr && count<k){
            fow=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fow;
            count++;
        }
        // recurse the rest of the nodes
        head->next=reverseKGroup(curr,k);
        
        // prev is the new head of the reverse list
        return prev;
    }
};