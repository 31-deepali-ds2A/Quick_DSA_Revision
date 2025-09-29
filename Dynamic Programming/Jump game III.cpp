#include<vector>
using namespace std;

// recusrive
class Solution {
public:
    int jump(vector<int>& nums) {
        return next(nums,0);
    }

    int next(vector<int>& nums,int i){
        if(i>=nums.size()-1) return 0;
    int minjump=INT_MAX;

        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()){
                int res=next(nums,i+j);
                if(res!=INT_MAX){
                    minjump=min(minjump,1+res);
                }
            }
        }
         return minjump;
    }
};

// memoization
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n+1,-1);
        return next(nums,0,memo);
    }

    int next(vector<int>& nums,int i,vector<int>& memo){
        if(i>=nums.size()-1) return 0;
        if(memo[i]!=-1) return memo[i];
        int minjump=INT_MAX;

        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()){
                int res=next(nums,i+j,memo);
                if(res!=INT_MAX){
                    minjump=min(minjump,1+res);
                }
            }
        }
         return memo[i]=minjump;
    }
};

// dp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;

        for(int i=n-2;i>=0;i--){
            int far=min(i+nums[i],n-1);

            for(int j=i+1;j<=far;j++){
                if(dp[j]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
        }
        return dp[0];
    }

    
};