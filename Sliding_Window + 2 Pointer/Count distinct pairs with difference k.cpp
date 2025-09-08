// Given an integer array of size n and a non-negative integer k, count all distinct pairs with
//  a difference equal to k, i.e., A[ i ] - A[ j ] = k.

#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    int TotalPairs(vector<int> nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count=0;
        
        if(k==0){
            for(auto& it:mp){
                if(it.second>1) count++;
            }
        }
        else{
            for(auto& it:mp){
                if(mp.find(it.first+k)!=mp.end()){
                    count++;
                }
            }
        }
        
        return count;
    }
};
