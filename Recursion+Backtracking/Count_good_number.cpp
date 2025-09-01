
// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 
// brute(TLE)
class Solution {
    const int MOD=1000000007;
public:
    int countGoodNumbers(long long n) {
       
       return solve(n,0,1);
        
    }
    long long solve(long long n,long long i,long long ans){
        if(i==n) return ans%MOD;
        if(i%2==0){
            ans=(ans*5)%MOD;
        }
       else
            ans=(ans*4)%MOD;
            
        return solve(n,i+1,ans);
        
       
    }
};


// optimized
class Solution {
    const int MOD=1000000007;
public:
    int countGoodNumbers(long long n) {
       
       long long even=(n+1)/2;
       long long odd=n/2;
       long long ans=(solve(even,5)*solve(odd,4)) %MOD;
        return int(ans);
    }
    long long solve(long long exp,long long base){

        if(exp==0) return 1;
        long long half=solve(exp/2,base);
        half=(half*half)%MOD;

        if(exp%2){
            half=(base*half)%MOD;
        }
        return half;
       
    }
};