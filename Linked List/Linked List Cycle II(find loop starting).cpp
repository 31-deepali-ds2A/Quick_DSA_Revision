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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                fast=head;
                while(fast!=slow){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        return nullptr;
       
    }
};