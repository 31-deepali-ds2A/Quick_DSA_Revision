// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.


#include<string>
#include<vector>
#include<algorithm>
using namespace std;


// brute force
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }

        vector<vector<int>> ans;
      possiblePermutation(nums,0,ans);
      sort(ans.begin(), ans.end());
        string temp="";
        
        for (int i = 0; i < n; i++) {
            temp += to_string(ans[k-1][i]);  // pick k-th permutation
        }
        return temp;
    }


    vector<vector<int>> possiblePermutation(vector<int>& nums,int i,vector<vector<int>>& ans){

        if(i==nums.size()){
            ans.push_back(nums);
            return ans;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            possiblePermutation(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
        return ans;
    }
};

// approach 2 using stl
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        for (int i = 1; i < k; i++) {
            next_permutation(nums.begin(), nums.end());
        }
         string temp = "";
        for (int i = 0; i < n; i++) {
            temp += to_string(nums[i]);
        }
        return temp;
    }


   
};

// optimised

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        vector<int> fact(n,1);
        for(int i=1;i<n;i++) fact[i]=fact[i-1]*i;

        k--;
        string ans="";

        for(int i=n;i>=1;i--){
            int idx=k/fact[i-1] ;// block
            k %= fact[i - 1];           // position inside block
            ans += to_string(nums[idx]);
            nums.erase(nums.begin() + idx); // remove used number
        }
        return ans;
    }
};