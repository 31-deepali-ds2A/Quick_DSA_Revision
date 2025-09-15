// You are given an integer array nums.
// A subsequence is stable if it does not contain three consecutive elements with the same parity when the subsequence is read in order (i.e., consecutive inside the subsequence).
// Return the number of stable subsequences.

// Since the answer may be too large, return it modulo 109 + 7.

// Example 1:
// Input: nums = [1,3,5]
// Output: 6

//--------------------------- Recently asked in Google OA -------------------------------------

#include<vector>
#include<algorithm>
using namespace std;

// recusrion
class Solution {
    const int MOD = 1e9+7;
public:
    int countStableSubsequences(vector<int>& nums) {
        return possible(nums, 0, -1, 0);
    }

    int possible(vector<int>& nums, long long idx, long long lastParity, long long cnt) {
        long long n = nums.size();
        
        if (cnt == 3) return 0;                      // invalid subsequence
        if (idx == n) return (lastParity != -1) ? 1 : 0; // valid if non-empty

        long long curParity = nums[idx] % 2;

        
        long long skip = possible(nums, idx+1, lastParity, cnt);

        long long newCnt;
        if (curParity == lastParity) {
            newCnt = cnt + 1;  // continue streak
        } else {
            newCnt = 1;        // start new streak
        }
        long long take = possible(nums, idx+1, curParity, newCnt);

        return (skip + take) % MOD;
    }
};


// memoization
class Solution {
    const int MOD = 1e9+7;
public:
    int countStableSubsequences(vector<int>& nums) {
        int n=nums.size();

        vector<vector<vector<int>>> memo(n, 
        vector<vector<int>>(3, vector<int>(3, -1)));

        return possible(nums, 0, -1, 0,memo);
    }

    int possible(vector<int>& nums, long long idx, long long lastParity, long long cnt,  vector<vector<vector<int>>>& memo) {
        long long n = nums.size();
        
        if (cnt == 3) return 0;                    
        if (idx == n) return (lastParity != -1) ? 1 : 0; 

        if(memo[idx][lastParity+1][cnt]!=-1) 
        return memo[idx][lastParity+1][cnt];

        long long curParity = nums[idx] % 2;

        
        long long skip = possible(nums, idx+1, lastParity, cnt,memo);

        long long newCnt;
        if (curParity == lastParity) {
            newCnt = cnt + 1;  // continue streak
        } else {
            newCnt = 1;        // start new streak
        }
    long long take = possible(nums, idx+1, curParity, newCnt,memo);

        return memo[idx][lastParity+1][cnt]= (skip + take) % MOD;
    }
};


// DP
class Solution {
    const int MOD = 1e9+7;
public:
    int countStableSubsequences(vector<int>& nums) {
        int n=nums.size();

        vector<vector<vector<int>>> dp(n+1, 
        vector<vector<int>>(3, vector<int>(3, 0)));

        // base case
        for(int lp=0;lp<3;lp++){
            for(int cnt=0;cnt<3;cnt++){
                dp[n][lp][cnt]=(lp!=0);
            // lp==0 means lastParity = -1 → empty subsequence → invalid
            }
        }

        for(int idx=n-1;idx>=0;idx--){
            int curParity=nums[idx]%2;

            for(int lp=0;lp<3;lp++){
                int lastParity=lp-1;
                for(int cnt=0;cnt<3;cnt++){
                    if(cnt==3) continue;

                    long long skip=dp[idx+1][lp][cnt];

                    int newcnt=(curParity==lastParity?cnt+1:1);

                    long long take=0;
                    if(newcnt<=2){
                        take=dp[idx+1][curParity+1][newcnt];
                    }
                    dp[idx][lp][cnt]=(skip+take)%MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};
