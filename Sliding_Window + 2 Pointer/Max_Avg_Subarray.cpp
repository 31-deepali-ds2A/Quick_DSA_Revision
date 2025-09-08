#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        
        // First window sum
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        double maxi = sum; // initialize with first window sum
        
        // Slide window
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            maxi = max(maxi, sum);
        }
        
        return maxi / k;  // return average
    }
};
