// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.


#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//brute
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(j-i<=k && nums[i]==nums[j]){
                    
                    return true;
                }
            }
        }
        return false;
        
    }
};

// sliding
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      
        int left=0;
        unordered_set<int> window;

         for(int i=0;i<nums.size();i++){
            if(window.count(nums[i])){
                return true;
            }
            window.insert(nums[i]);

            if(i-left>=k){
                window.erase(nums[left]);
                left++;
            }
         }

        return false;
        
    }
};

// map
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        // map will store the latest index of nums[i]

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            // if nums[i] is  present in map, then check the condition

            if(mp.count(nums[i]))
            {
                if(abs(i - mp[nums[i]]) <= k)
                {
                    return true;
                }
            }

            // insert nums[i] into map

            mp[nums[i]] = i;
        }

        return false;
    }
};