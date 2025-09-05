// Given an integer array nums and an integer k, return the k most frequent elements. You may 
// return the answer in any order.

#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// using-min-heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min-heap
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto& it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty() ){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
            
    }

};

//using max-heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int num : nums) {
            mp[num]++;
        }

       
        priority_queue<pair<int,int>> pq;  //max-heap
        for (auto& it : mp) {
            pq.push({it.second, it.first}); 
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


// Min-heap is better when k << n.