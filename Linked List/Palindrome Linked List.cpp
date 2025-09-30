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

  // brute force -> O(n ) & space-> O(n)
  class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        if(head==NULL) return false;

        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        int size=arr.size();
        int i=0,j=size-1;

        while(i<=j){
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
       }
       return true;
    }
};

// optimal ->O(n) & O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* mid=middle(head);
        ListNode* revList=reverse(mid);

        while( revList!=nullptr){
            if(temp->val!=revList->val){
                return false;
            }
            temp=temp->next;
            revList=revList->next;
        }
        return true;
    }

    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
       // cout<<slow->val<<" ";
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* fow=nullptr;

        while(curr!=nullptr){
            fow=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fow;
        }
        return prev;
    }
};