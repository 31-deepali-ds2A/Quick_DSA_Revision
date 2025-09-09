// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int count=atMost(nums,k)-atMost(nums,k-1);
        return count;
    }
     int atMost(vector<int>& nums, int k) {
        int l=0, r=0;
        int n=nums.size();
        int count=0;
        int cntK=0;

        while(r<n){
           
            if(nums[r]%2){
                cntK++;
            }
            
            while(cntK>k && l<=r){
                if (nums[l] % 2) cntK--;
                    l++;

                }
            count+=(r-l+1);
            
           r++;
        }
        return count;
    }
};