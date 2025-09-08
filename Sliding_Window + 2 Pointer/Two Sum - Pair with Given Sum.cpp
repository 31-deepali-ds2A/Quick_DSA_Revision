// Given an array arr[] of integers and another integer target. Determine if there exist two
//  distinct indices such that the sum of their elements is equal to the target.

#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// better than brute
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            int t=(target-arr[i]);
            if(mp.find(t)!=mp.end()){
                return true;
            }
            mp[arr[i]]=i;
        }
        return false;
        
        
    }
};

// optimal(2 pointer)
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int left=0;
        int right=arr.size()-1;
        
        while(left<right){
            if(arr[left]+arr[right]==target) return true;
            if(arr[left]+arr[right]<target){
                left++;
            }
            else {
                right--;
            }
        }
        
        
        return false;
        
        
    }
};