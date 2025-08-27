#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    // 🔹 Approach 1: XOR Method
    int missingNum_XOR(vector<int>& arr) {
        int n = arr.size();
        int x1 = 0, x2 = 0;

        for (int i = 1; i <= n + 1; i++) {
            x1 ^= i;
        }
        for (int i = 0; i < n; i++) {
            x2 ^= arr[i];
        }
        return x1 ^ x2;
    }

    // 🔹 Approach 2: Sum Formula
    int missingNum_Sum(vector<int>& arr) {
        int n = arr.size();
        long long Esum = 1LL * (n + 1) * (n + 2) / 2; // expected sum
        long long Osum = 0; // observed sum

        for (int i = 0; i < n; i++) {
            Osum += arr[i];
        }
        return (int)(Esum - Osum);
    }

    // 🔹 Approach 3: Sorting
    int missingNum_Sort(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return arr[n - 1] + 1;
    }
};

int main() {
    vector<int> arr = {1, 2, 4, 5}; // Example input (missing 3)

    Solution obj;

    cout << "Missing Number (XOR): " << obj.missingNum_XOR(arr) << endl;
    cout << "Missing Number (Sum Formula): " << obj.missingNum_Sum(arr) << endl;
    cout << "Missing Number (Sorting): " << obj.missingNum_Sort(arr) << endl;

    return 0;
}
