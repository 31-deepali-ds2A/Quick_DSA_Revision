//Given an array arr[], find the sum of all the subarrays of the given array.

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach (O(n^2)) -> may give TLE
class BruteForceSolution {
  public:
    int subarraySum(vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            int temp = 0;
            for(int j = i; j < arr.size(); j++) {
                temp += arr[j];
                sum += temp;
            }
        }
        return sum;
    }
};

// Optimized Approach (O(n)) -> Contribution Technique
class OptimizedSolution {
  public:
    int subarraySum(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            sum += arr[i] * (i + 1) * (n - i);
        }
        return sum;
    }
};

// Driver code
int main() {
    vector<int> arr = {1, 2, 3};
    
    BruteForceSolution brute;
    OptimizedSolution opt;

    cout << "Brute Force Result: " << brute.subarraySum(arr) << endl;
    cout << "Optimized Result: " << opt.subarraySum(arr) << endl;

    return 0;
}
