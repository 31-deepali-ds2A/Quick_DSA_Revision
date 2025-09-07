#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 //rotate left;

// Using reverse method (Optimal O(n), O(1))
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

       
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
         reverse(nums.begin(), nums.end());
    }
};