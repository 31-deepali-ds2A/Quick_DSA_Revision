// Input: nums = [2,5,6,0,0,1,2], target = 0 (duplicates also present)
// Output: true


#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[left] && nums[right]==nums[mid]){
                left++;
                right--;
            }
            else if( nums[left]<=nums[mid] ){
                if(target>=nums[left] && target<nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{
                if(target>nums[mid] && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return false;
    }
};