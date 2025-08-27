#include <iostream>
#include <vector>
#include <numeric>   // for accumulate
using namespace std;

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        int prefix = 0;
        int total = accumulate(arr.begin(), arr.end(), 0);
        int suffix = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefix += arr[i - 1];
            }

            suffix = total - prefix - arr[i];

            if (prefix == suffix) {
                return i; // equilibrium index
            }
        }
        return -1;
    }
};

// ===================
// Driver Code
// ===================
int main() {
    vector<int> arr = {1, 3, 5, 2, 2};

    Solution obj;
    int index = obj.findEquilibrium(arr);

    if (index != -1)
        cout << "Equilibrium index: " << index << endl;
    else
        cout << "No Equilibrium Point Found" << endl;

    return 0;
}
