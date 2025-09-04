// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2

#include<vector>
#include<algorithm>
using namespace std;

//brute force
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=INT_MAX;
        int sum;
        int len=0;

        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>=target){
                    minLen=min(minLen,j-i+1);
                }
            }
        }
        return minLen==INT_MAX ? 0: minLen;
    }
};


//optimal

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=INT_MAX;
        int sum=0;
        int left=0, right=0;
        while(right<nums.size()){

            
                sum+=nums[right];
                right++;
            
            while(sum>= target && left<=right){
                minLen=min(minLen,right-left);
                sum-=nums[left];
                left++;
                
            }
           
        }
        return minLen==INT_MAX ? 0: minLen;
    }
};