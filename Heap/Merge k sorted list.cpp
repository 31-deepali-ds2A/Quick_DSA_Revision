
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;



 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

  // optimal O(n log k)
class Solution {
public:
      struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;

        for(auto node:lists){
            if(node) pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail=&dummy;

        while(!pq.empty()){
            ListNode* curr=pq.top();
            tail->next=curr;
            pq.pop();
            tail=tail->next;
            
            if(curr->next){
                pq.push(curr->next);
            }
        }
        return dummy.next;
    }
};