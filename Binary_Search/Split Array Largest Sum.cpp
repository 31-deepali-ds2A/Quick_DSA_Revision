
// similar to book allocation problem

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

        if(low>high) return -1;

        while(low<high){
            int mid=low+(high-low)/2;
            if(canSplit(nums,mid)>k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }

    int canSplit(vector<int>& nums,int mid){
        int split=1;
        int sum=0;
        for(int num:nums){
           if(sum+num>mid){
            split++;
            sum=num;
           }
           else sum+=num;
        }
        return split;
    }
};