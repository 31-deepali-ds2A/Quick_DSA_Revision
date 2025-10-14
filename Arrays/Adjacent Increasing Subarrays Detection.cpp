// Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays starting at indices a and b (a < b), where:

// Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
// The subarrays must be adjacent, meaning b = a + k.
// Return true if it is possible to find two such subarrays, and false otherwise.

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();~
        int cnt=1, precnt=0, ans=0;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt++;
            }
            else{
                precnt=cnt;
                cnt=1;
            }
            ans=max(ans,min(precnt,cnt));
            ans=max(ans,cnt/2);
        }
        return ans>=k;
    }
};