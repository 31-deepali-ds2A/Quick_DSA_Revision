//Given a sorted array of distinct integers and a target value, return the index if the 
//target is found. If not, return the index where it would be if it were inserted in order.

#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int left=0,right=nums.size()-1;
        int mid=0;
        while(left<=right){
             mid=left+(right-left)/2;

            if(nums[mid]==target) return mid;

            else if(target>nums[mid]){
                
                 left=mid+1;
            }
            else{
                
                right=mid-1;
            }
        }
        return target>nums[mid] ? mid+1: mid;
    }
};

