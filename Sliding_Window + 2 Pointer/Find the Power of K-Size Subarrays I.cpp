// You are given an array of integers nums of length n and a positive integer k.

// The power of an array is defined as:
// Its maximum element if all of its elements are consecutive and sorted in ascending order.
// -1 otherwise.
// You need to find the power of all subarrays of nums of size k.
// Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].


#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        int breaks=0;

        for(int i=0;i<k-1;i++){
            if(nums[i]+1!=nums[i+1]){
                breaks++;
            }
        }
        if(breaks==0){
            res.push_back(nums[k-1]);
        }
        else res.push_back(-1);

        for(int i=k;i<n;i++){
            
                if(nums[i-k]+1!=nums[i-k+1]){
                    breaks--;
                }
                if(nums[i]!=nums[i-1]+1){
                    breaks++;
                   
                }
            res.push_back(breaks == 0 ? nums[i] : -1);
        }
        return res;
    }
};