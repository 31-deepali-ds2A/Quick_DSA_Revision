/*
🔹 Problem Statement:
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Example:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Approach:
We use a modified Binary Search to locate the target.
Once found, expand to the left and right to capture the full range.
Time Complexity: O(log n + k), where k = count of target elements.
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                int il = mid, jl = mid;

                // Expand leftwards
                while (il >= 0 && nums[il] == target) il--;

                // Expand rightwards
                while (jl < n && nums[jl] == target) jl++;

                start = il + 1;
                end = jl - 1;
                break;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return {start, end};
    }
};

// Driver Code (For VS Code Testing)
int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = sol.searchRange(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    return 0;
}
