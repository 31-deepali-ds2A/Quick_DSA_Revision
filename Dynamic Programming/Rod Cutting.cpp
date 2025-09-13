


#include<vector>
#include<algorithm>
using namespace std;

// recusrion
// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        return maxPrice(price,n);
    }
    
    int maxPrice(vector<int>& price,int n){
        if(n==0) return 0;
        int best=INT_MIN;
        
        for(int i=1;i<=n;i++){  // try for every starting idx i
            
        int cutsVal=price[i-1]+ maxPrice(price,n-i);
        best=max(best,cutsVal);
        
        }
        
        return best;
    }
};

// memoization

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int> memo(n+1,-1);
        return maxPrice(price,n,memo);
    }
    
    int maxPrice(vector<int>& price,int n,vector<int>& memo){
        if(n==0) return 0;
        if(memo[n]!=-1) return memo[n];
        int best=INT_MIN;
        
        for(int i=1;i<=n;i++){
            
        int cutsVal=price[i-1]+maxPrice(price,n-i,memo);
        best=max(best,cutsVal);
        
        }
        
        return memo[n]=best;
    }
};

// DP--> O(n^2)

class Solution {
  public:
    int cutRod(vector<int> &price) {
     
        int n=price.size();
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            int best=INT_MIN;
            for(int j=1;j<=i;j++){
            int cur=price[j-1]+dp[i-j];
            best=max(best,cur);
            }
            dp[i]=best;
        }
        return dp[n];
    }
};

