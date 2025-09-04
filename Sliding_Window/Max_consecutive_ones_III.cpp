#include<vector>
#include<algorithm>
using namespace std;

// brute force
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            int zcnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zcnt++;
                if (zcnt > k) break;  // stop early since further extension will only add more zeros
                maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};

//optimal
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0;
        int zcnt=0;
        int maxlen=0;

        while(right<nums.size()){

            while(zcnt>k && left<=right){
                if(nums[left]==0) zcnt--;
                left++;  
            }
            if(nums[right]==0) zcnt++;
            right++;
            if(zcnt<=k)
                maxlen=max(maxlen,right-left);
        }
        return maxlen;
    }
    
};
