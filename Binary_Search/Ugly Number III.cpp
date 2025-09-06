// An ugly number is a positive integer that is divisible by a, b, or c.

// Given four integers n, a, b, and c, return the nth ugly number.

#include<vector>
#include<algorithm>
using namespace std;

//brute force
 class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int mini=min(a,min(b,c));
        if(n==1) return mini;
        while(n>1){
             mini++;
            if(mini%a==0 || mini%b==0 || mini%c==0){
                n--;
            }
           
        }
        return mini;
    }
};

// optimal
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
       
      long long ab=lcm(a,b);
      long long bc=lcm(c,b);
      long long ca=lcm(a,c);
      long long abc=lcm(ab,c);

      long long left=1, right=2e18;
     // long long left=min(a,min(b,c));  we can start range from here also, better range bound

      while(left<right){
        long long mid=left+(right-left)/2;
        long long count=mid/a + mid/b + mid/c
                -mid/ab - mid/bc - mid/ca + mid/abc; // inclusion-exclusion principle
        if(count<n) left=mid+1;
        else right=mid;
      }
      return int(left);
    }

    long long gcd(long long x,long long y){
        return y==0 ? x:gcd(y,x%y); //extended eculidean algorithm
    }
    long long lcm(long long x, long long y){
        return x/gcd(x,y)*y; // handling overflow as well
    }
};