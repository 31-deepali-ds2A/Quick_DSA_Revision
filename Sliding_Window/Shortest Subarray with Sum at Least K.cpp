// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

// A subarray is a contiguous part of an array

#include<vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;

//brute force
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int minlen=INT_MAX;
        int i,j;

        for( i=0;i<nums.size();i++){
            int sum=0;
            for( j=i;j<nums.size();j++){
               sum+=nums[j];
               if(sum>=k){
                     minlen=min(minlen,j-i+1);
               }
                
            }
           
        }
        return minlen==INT_MAX?-1:minlen;
    }
};

// this solution will only works if all nums[i] are +ve (fails for -ve)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int minlen=INT_MAX;
        int left=0,sum=0;

        for(int right=0;right<nums.size();right++){
        
               sum+=nums[right];
               while(sum>=k){
                minlen=min(minlen,right-left+1);
                    sum-=nums[left];
                    left++;
                 
               }
              
            }
        return minlen==INT_MAX?-1:minlen;
    }
};

//optimal- deque + prefix sum (handles -ves)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       
        int n=nums.size();
         int minlen=n+1;
        deque<int> dq;
        vector<long long> prefix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        for(int right=0;right<=n;right++){
            
            while(!dq.empty() && prefix[right]-prefix[dq.front()]>=k){
                minlen=min(minlen,right-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[right]<=prefix[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);
             
            }
        return minlen==n+1?-1:minlen;
    }
};