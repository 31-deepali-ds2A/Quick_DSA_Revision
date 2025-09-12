// Given n items, each with a specific weight and value, and a knapsack with a capacity of W, 
// the task is to put the items in the knapsack such that the sum of weights of the items
//  <= W and the sum of values associated with them is maximized. 

// Note: You can either place an item entirely in the bag or leave it out entirely. Also,
//  each item is available in single quantity.

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
// Output: 3

#include<vector>
#include<algorithm>
using namespace std;


// recusrion
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        return maxVal(W,val,wt,0);
        
    }
    int maxVal(int W,vector<int>& val,vector<int>& wt,int idx){
        
        if(idx>=val.size() || W==0) return 0;
        
        int take=0, nottake=0;
        
        if(W-wt[idx]>=0){
            take=val[idx]+maxVal(W-wt[idx],val,wt,idx+1);
        }
        nottake=maxVal(W,val,wt,idx+1);
        
        return max(take,nottake);
        
    }
};

// memoization
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> memo(n+1,vector<int>(W+1,-1));
        return maxVal(W,val,wt,0,memo);
        
    }
    int maxVal(int W,vector<int>& val,vector<int>& wt,int idx,
    vector<vector<int>>& memo){
        
        if(idx>=val.size() || W==0) return 0;
       
        if(memo[idx][W]!=-1) return memo[idx][W];
        
        int take=0, nottake=0;
        
        if(W-wt[idx]>=0){
            take=val[idx]+maxVal(W-wt[idx],val,wt,idx+1,memo);
        }
        nottake=maxVal(W,val,wt,idx+1,memo);
        
        return memo[idx][W]=max(take,nottake);
        
    }
};

// Dp(bottom-up)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int weight=0;weight<=W;weight++){
                
                int take=0,nottake=0;
                
                if(weight-wt[idx]>=0){
                    
                    take=val[idx] + dp[idx+1][weight-wt[idx]];
                }
                nottake=dp[idx+1][weight];
                
                dp[idx][weight]=max(take,nottake);
            }
        }
        return dp[0][W];
       
        
    }
   
};