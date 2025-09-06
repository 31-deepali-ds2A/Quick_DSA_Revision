#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = n - 2;

        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;  // found peak
            }
            else if (nums[mid] > nums[mid - 1]) {
                left = mid + 1;  // we are on increasing slope
            }
            else {
                right = mid - 1; // we are on decreasing slope
        }

        return -1; // should not happen
    }
}
};

