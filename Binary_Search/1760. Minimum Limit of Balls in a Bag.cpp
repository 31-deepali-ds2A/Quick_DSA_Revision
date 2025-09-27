// You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

// You can perform the following operation at most maxOperations times:
// Take any bag of balls and divide it into two new bags with a positive number of balls.
// For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
// Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

// Return the minimum possible penalty after performing the operations.

// Input: nums = [9], maxOperations = 2
// Output: 3

#include<vector>
#include<algorithm>
using namespace std;

// using linear search  -> O(n × maxi)c
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxi=*max_element(nums.begin(),nums.end());

        for(int i=1;i<=maxi;i++){
            if(can_divide(i,maxOperations,nums)){
                return i;
            }
        }
        return -1;
    }

    bool can_divide(int max_balls,int maxOp,vector<int>& nums){
         long long ops = 0; 
        for (int it : nums) {
            ops += ceil((double)it / max_balls) - 1;
            if (ops > maxOp) return false;
        }
        return true;
    }
};

// using binary search on answers -> O(nlogk)
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int right=*max_element(nums.begin(),nums.end()); // max limit
        int left=1;
        int ans=right;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(can_divide(mid,maxOperations,nums)){
                ans=mid; 
                right=mid-1; // try smaller
            }
            else{
                left=mid+1; // too less, try more
            }
        }
        return ans;
    }

    bool can_divide(int max_balls,int maxOp,vector<int>& nums){
         long long ops = 0; 
        for (int it : nums) {
            ops += ceil((double)it / max_balls) - 1;
           // OR  ops += (it - 1) / max_balls;  
           
            if (ops > maxOp) return false;
        }
        return true;
    }
};