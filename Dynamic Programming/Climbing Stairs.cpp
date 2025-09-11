// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can 
// you climb to the top?

#include<vector>
using namespace std;

// this ques is forming a fibonnaci-->> 1,2,3,4,5,....so on

//recusrion
class Solution {
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n==0 || n==1) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

// memoization( to show overlapping)
class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // Base cases
        if (n == 0) return 1;   // 1 way (stay on ground)
        if (n == 1) return 1;   // 1 way (1 step)

        // Already computed?
        if (dp[n] != -1) return dp[n];

        // Recurrence: take 1 step or 2 steps
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// dp
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
    
        vector<int> dp(n,0);
        // base case
        dp[0]=1;
        dp[1]=2;

        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};

//space optimization
class Solution {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev1=2;
        // base case
        if(n==1) return 1;
        if(n==2) return 2;

        int curr=0;

        for(int i=2;i<n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};

