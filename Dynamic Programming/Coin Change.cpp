// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1


#include<vector>
#include<algorithm>
using namespace std;

// recusrion

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans= maxTake(coins,amount,0);
        return ans>=1e9? -1 : ans;
    }
    int maxTake(vector<int>& coins,int amount,int idx){
        if(amount==0) return 0;
        // found a valid case

        if(idx>=coins.size()) return 1e9; 
        // we reached till end but not able to make up amount

        int take=1e9;
        if(amount>=coins[idx]){
            int res=maxTake(coins,amount-coins[idx],idx);
            if(res!=1e9) take=1+res; // to avoid overflow
        }

        int nottake=maxTake(coins,amount,idx+1);

        return min(take,nottake);

    }
};


// memoization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> memo(n+1,vector<int>(amount+1,-1));
        int ans= maxTake(coins,amount,0,memo);
        return ans>=1e9? -1 : ans;
    }
    int maxTake(vector<int>& coins,int amount,int idx,
    vector<vector<int>>& memo){

        if(amount==0) return 0;
        // found a valid case

        if(idx>=coins.size()) return 1e9; 
        // we reached till end but not able to make up amount

         if(memo[idx][amount]!=-1) return memo[idx][amount]; // already calculated

        int take=1e9;
        if(amount>=coins[idx]){
            int res=maxTake(coins,amount-coins[idx],idx,memo);
            if(res!=1e9) take=1+res; // to avoid overflow
        }

        int nottake=maxTake(coins,amount,idx+1,memo);

        return memo[idx][amount]= min(take,nottake);

    }
};


// dp 2D
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(amount+1, INF));

        // Base case: 0 amount requires 0 coins
        for (int i = 0; i < n; i++) dp[i][0] = 0;

        // First row (using only coins[0])
        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0) dp[0][j] = j / coins[0];
        }

        // Fill table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                int nottake = dp[i-1][j];
                int take = INF;
                if (j >= coins[i]) {
                    take = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(take, nottake);
            }
        }

        return dp[n-1][amount] >= INF ? -1 : dp[n-1][amount];
    }
};



// dp (1 D)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;  
        vector<int> dp(amount + 1, INF);

        dp[0] = 0;  // base case: 0 coins needed to make amount 0

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                if (dp[j - coin] != INF) {
                    dp[j] = min(dp[j], 1 + dp[j - coin]);
                }
            }
        }

        return dp[amount] >= INF ? -1 : dp[amount];
    }
};
