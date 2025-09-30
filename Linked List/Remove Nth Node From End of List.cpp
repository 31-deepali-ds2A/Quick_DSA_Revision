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



// two pass sol
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;

        // Step 1: calculate length
        while(temp != nullptr) {
            length++;
            temp = temp->next;
        }
        // Step 2: if we need to delete head
        if(n == length) {
            return head->next;
        }
        // Step 3: find (length-n)th node
        temp = head;
        for(int i=1; i<length-n; i++) {
            temp = temp->next;
        }
        // Step 4: remove node
        temp->next = temp->next->next;
        return head;
    }
};

// one pass sol
  class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;

        for(int i=0;i<n;i++){
            if(fast->next==nullptr){
                return head->next;
            }
            fast=fast->next;
        }

        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;

        }
        ListNode* del=slow->next;
        slow->next=slow->next->next;
        return head;
    }
};