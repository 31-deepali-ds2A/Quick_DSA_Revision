// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.a
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.


// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

#include<vector>
#include<numeric>
using namespace std;

// recusrion
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return possibleWays(nums,target,0,0);
    }
    int possibleWays(vector<int>& nums,int target,int idx,int sum){

        if(idx==nums.size()) return sum == target ? 1 : 0;
        // found 1 possible way

        int takePlus=0, takeNeg=0;
       
        takePlus+=possibleWays(nums,target,idx+1,sum+nums[idx]);
        takeNeg+=possibleWays(nums,target,idx+1,sum+(-nums[idx]));
        
        return takePlus + takeNeg;
    }
};

// memoization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);

        // If target out of possible range, no solutions
        if(abs(target) > total) return 0;

        vector<vector<int>> memo(n+1,vector<int>(2*total+1,-1));
        // size=2*total+1--> bcz sum can be neg(-) as well

        return possibleWays(nums,target,0,0,memo,total);
    }

    int possibleWays(vector<int>& nums,int target,int idx,int sum,
    vector<vector<int>>& memo,int total)  {

       
        if(idx==nums.size()) return sum==target?1:0;
        // found 1 possible way

         if(memo[idx][sum+total]!=-1)
          return memo[idx][sum+total]; // shift sum by +total

        int takePlus=0, takeNeg=0;
       
        takePlus+=possibleWays(nums,target,idx+1,
                                sum+nums[idx],memo,total);

        takeNeg+=possibleWays(nums,target,idx+1,
                            sum+(-nums[idx]),memo,total);
        
        return memo[idx][sum+total]= takePlus + takeNeg;
    }
};

// bottom-up (DP)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);

        // If target out of possible range, no solutions
        if(abs(target) > total) return 0;

        vector<vector<int>> dp(n+1,vector<int>(2*total+1,0));
        // size=2*total+1--> bcz sum can be neg as well

        dp[0][total]=1;  // base case

        for(int i=1;i<=n;i++){
            int num=nums[i-1];
            for(int s=0;s<=2*total;s++){

                if(dp[i-1][s]!=0){
                    if(s+num<=2*total)
                        dp[i][s+num]+=dp[i-1][s];
                    if(s-num>=0)
                        dp[i][s-num]+=dp[i-1][s];
                }
            }
        }
        return dp[n][target+total];
    }
    
};