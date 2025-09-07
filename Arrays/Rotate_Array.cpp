#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 //rotate right;
// ====================== Approach 1 ======================
// Using reverse method (Optimal O(n), O(1))
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// ====================== Approach 2 ======================
// Using extra array (O(n), O(n))
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        vector<int> temp;
        for (int i = size - 1; i >= size - k; i--) {
            temp.push_back(nums[i]);
            nums.pop_back();
        }

        vector<int> res;
        int n = temp.size();
        for (int i = n - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }

        for (int i = 0; i < size - k; i++) {
            res.push_back(nums[i]);
        }

        nums = res;
    }
};

// ====================== Approach 3 (Brute) ======================
// Shifting one-by-one (O(n*k), O(1)) -> TLE for large k
class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        while (k > 0) {
            int t = nums[size - 1];
            nums.pop_back();
            nums.insert(nums.begin(), t);
            k--;
        }
    }
};
