// Given a collection of numbers, nums, that might contain duplicates, return all possible 
//unique permutations in any order.

#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

// using set O(n⋅n!⋅log(n!))
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        possiblePermute(nums,0,res);
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
    void possiblePermute(vector<int>& nums,int idx,set<vector<int>>& res){
    
        if(idx==nums.size()){
            res.insert(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            possiblePermute(nums,idx+1,res);
            swap(nums[i],nums[idx]);
        }
    }
};

// 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // sort first
        backtrack(nums, 0, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used; // track duplicates at this level
        for (int i = idx; i < nums.size(); i++) {
            if (used.count(nums[i])) continue; // skip duplicate
            used.insert(nums[i]);
            swap(nums[i], nums[idx]);
            backtrack(nums, idx + 1, ans);
            swap(nums[i], nums[idx]); // backtrack
        }
    }
};
