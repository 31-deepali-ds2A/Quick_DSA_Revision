#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int currEnd=0,far=0,minjump=0;

        for(int i=0;i<n-1;i++){
            far=max(far,i+nums[i]);
            if(i==currEnd){
                minjump++;
                currEnd=far;
            }
        }
        return minjump;
    }
};