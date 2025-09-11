


#include<vector>
#include<algorithm>
using namespace std;

// recursive
class Solution {
public:
    int rob(vector<int>& nums) {
        return maxMoney(nums,0);
    }
    int maxMoney(vector<int>& nums,int idx){
        if(idx>=nums.size()) return 0; //base case

        int take=nums[idx]+maxMoney(nums,idx+2); // Current ghar looto
        int nottake=maxMoney(nums,idx+1); //Current ghar skip karo

        return max(take,nottake);
    }
};

//memoization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n+1,-1);
        return maxMoney(nums,0,memo);
    }
    int maxMoney(vector<int>& nums,int idx,vector<int>& memo){
        if(idx>=nums.size()) return 0; //base case
        if(memo[idx]!=-1) return memo[idx]; //overlapping(already calculated)

    int take=nums[idx]+maxMoney(nums,idx+2,memo); //Current ghar looto
    int nottake=maxMoney(nums,idx+1,memo); //Current ghar skip karo

        return memo[idx]= max(take,nottake);
    }
};

// Dp(bottom-up)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
         if (n == 0) return 0;
        if (n == 1) return nums[0]; 

        vector<int> dp(n+1,0);
      
        dp[n] = 0;            
        dp[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            int take=nums[i]+dp[i+2];
            int nottake=dp[i+1];
            dp[i]=max(take,nottake);
        }
        return dp[0];;
    }
    
};

// Dp(forword-filling)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);

        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Fill forward
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }
};
 
// space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
         if (n == 0) return 0;
        if (n == 1) return nums[0]; 

        vector<int> dp(n+1,0);
      
       int prev2 = 0;            
       int prev1 = nums[n-1];
       int curr=0;

        for(int i=n-2;i>=0;i--){
            int take=nums[i]+prev2;
            int nottake=prev1;
             curr=max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
    
};