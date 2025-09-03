#include<vector>
#include<unordered_map>
#include<queue>
#include <functional>
using namespace std;

// You are given an array nums of n integers and two integers k and x.
// The x-sum of an array is calculated by the following procedure:
// Count the occurrences of all elements in the array.
// Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
// Calculate the sum of the resulting array.
// Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
// Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> res;
        int sum=0;

        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
                                greater<pair<int,int>>> pq; //min-heap
        // top x -frequent
    
        for(auto &p : mp) {
            pq.push({p.second, p.first});
            if(pq.size() > x) pq.pop();
        }
        while(!pq.empty()){
            sum+= pq.top().second*pq.top().first;
            pq.pop();
        }
        res.push_back(sum);

 // slide window for rest

        for(int i=k;i<n;i++){
            sum=0;
            mp[nums[i-k]]--;
            mp[nums[i]]++;

            for(auto &p : mp) {
            pq.push({p.second, p.first});
            if(pq.size() > x) pq.pop();
        }
        while(!pq.empty()){
            sum+= pq.top().second*pq.top().first;
            pq.pop();
        }
        res.push_back(sum);
        }
        return res;
    }
};