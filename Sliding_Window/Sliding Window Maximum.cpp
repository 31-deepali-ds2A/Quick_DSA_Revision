// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

#include<vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;


// Better than brute
//Best case: O(n) (if max rarely leaves the window).
// Worst case: O(n·k) (if max leaves every time, e.g. decreasing array).
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        int maxi=INT_MIN;

        for(int i=0;i<k;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        res.push_back(maxi);

        for(int i=k;i<n;i++){

            if(nums[i-k]==maxi){
                maxi=INT_MIN;
                for(int j=i-k+1;j<=i;j++){
                    if(nums[j]>maxi){
                        maxi=nums[j];
                    }
                }
            }
            else if(nums[i]>maxi){
                maxi=nums[i];
            }
            res.push_back(maxi);

        }
        return res;
    }
};

// using heap O(n log k), space=O(k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> res;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
           
            
            if(i>=k-1){
                while(!pq.empty() && pq.top().second<=i-k){
                    pq.pop();
                }
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};

//optimal (using deque) O(n),space=O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i=0;i<nums.size();i++){

            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};