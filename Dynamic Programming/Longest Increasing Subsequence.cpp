#include<vector>
#include<algorithm>
using namespace std;

// recusrion
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return findLen(nums,0,-1);
    }
    int findLen(vector<int>& nums,int idx,int prev){

        if(idx>=nums.size()) return 0;
        int take=0,skip;
        
        if(prev==-1 || nums[idx]>nums[prev]){
            take=1+findLen(nums,idx+1,idx);
        }
        skip=findLen(nums,idx+1,prev);

        return max(take,skip);
    }
};

// memoization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return findLen(nums,0,-1,memo);
    }
    int findLen(vector<int>& nums,int idx,int prev,vector<vector<int>>& memo){

        if(idx>=nums.size()) return 0;
        if(memo[idx][prev+1]!=-1) return memo[idx][prev+1];
        int take=0,skip;
        
        if(prev==-1 || nums[idx]>nums[prev]){
            take=1+findLen(nums,idx+1,idx,memo);
        }
        skip=findLen(nums,idx+1,prev,memo);

        return memo[idx][prev+1]=max(take,skip);
    }
};

// bottom-up

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                 int skip = dp[i+1][prev+1];

                 int take=0;
              if(prev==-1 || nums[prev]<nums[i]){
                take=1+dp[i+1][i+1];
              }
              dp[i][prev+1]=max(take,skip);
            }
            
        }
        return dp[0][0];
    }
   
};

// another way of writing dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1); // base case, every single element will have 1 length

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};