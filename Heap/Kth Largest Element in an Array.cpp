// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Time:
// Push: O(log k)
// Do it n times → O(n log k)
// Space: O(k) for heap.

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq; //min-heap
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

//using map-heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> pq(nums.begin(), nums.end()); //max-heap
            for (int i = 0; i < k-1; i++) pq.pop();
            return pq.top();
    }
};