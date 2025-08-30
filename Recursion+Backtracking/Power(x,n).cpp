// implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 3:
// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25


class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) {
            x=(1/x);
            n=-(n);
        }
        double ans=1;
        return powN(x,n,ans);
    }

    double powN(double x, int n,double ans){
        if(n<1) return ans;
         return powN(x,n-1,ans*x);
    }
};

// exponention
#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            if (n == INT_MIN) return 1.0 / (myPow(x, INT_MAX) * x);
            return 1.0 / myPow(x, -n);
        }
        if (n % 2 == 0)
            return myPow(x * x, n / 2);
        else
            return x * myPow(x, n - 1);
    }
};
