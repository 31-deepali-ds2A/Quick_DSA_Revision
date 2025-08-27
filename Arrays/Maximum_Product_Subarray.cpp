#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// =========================
// Brute Force Approach
// =========================
class SolutionBrute {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxPro = INT_MIN;
        int pro = 1;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            maxPro = max(curr, maxPro);
            for (int j = i; j < n; j++) {
                pro *= nums[j];
                maxPro = max(pro, maxPro);
            }
            pro = 1;
        }
        return maxPro;
    }
};

// =========================
// Optimized Observation Approach
// =========================
class SolutionOptimized {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxPro = INT_MIN;
        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            maxPro = max(maxPro, max(prefix, suffix));
        }
        return maxPro;
    }
};

// =========================
// Driver Code (Test Both Approaches)
// =========================
int main() {
    vector<int> nums = {2, 3, -2, 4};  // Example input

    SolutionBrute bruteSolver;
    SolutionOptimized optSolver;

    cout << "Brute Force Result: " << bruteSolver.maxProduct(nums) << endl;
    cout << "Optimized Result: " << optSolver.maxProduct(nums) << endl;

    return 0;
}
