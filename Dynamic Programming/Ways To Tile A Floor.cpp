// Given a floor of dimensions 2 x n and tiles of dimensions 2 x 1, the task is to find the 
// number of ways the floor can be tiled. A tile can either be placed horizontally i.e 
// as a 1 x 2 tile or vertically i.e as 2 x 1 tile. 

#include<vector>
#include<algorithm>
using namespace std;

// ye fibonacci series bana rha hai-->> 2,3,5,8,..so on

// recursion
class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        
        if(n<0) return 0;
        if(n==0 || n==1) return 1;
        return numberOfWays(n-1)+numberOfWays(n-2);
    }
};

// memoization
class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        vector<int> memo(n+1,-1);
       return solve(memo,n);
      
    }
    int solve(vector<int>& memo,int n){
         if(n<0) return 0;
        if(n==0 || n==1) return 1;
         
        if(memo[n]!=-1) return memo[n];
        
        return memo[n]=solve(memo,n-1)+solve(memo,n-2);
    }
};

// dp(tabulation)
class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        vector<int> dp(n+1,0);
        
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
       
      
    }
    
};