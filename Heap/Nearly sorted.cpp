// Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
// Note: You need to change the given array arr[] in place.

#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


// by direct sort fun O(n log n)---- approach 1

// O(n log n) & space O(n)--- approach 2
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto& it:arr) pq.push(it);
        
        int i=0;
        while(!pq.empty()){
            arr[i]=pq.top();
            pq.pop();
            i++;
        }
        return ;
    }
};

// O(n log k) & space O(k)---approach 3
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<=k;i++) pq.push(arr[i]);
        
        int idx=0;
        for(int i=k+1;i<arr.size();i++){
            arr[idx++]=pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
         while(!pq.empty()){
             arr[idx++]=pq.top();
             pq.pop();
         }
         return ;
    }
};