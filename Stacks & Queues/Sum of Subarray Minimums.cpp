#include<stack>
#include<vector>
using namespace std;

// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17


// brute force
// find all subarray-> check min in each -> sum all

// optimal
class Solution {
    const int MOD=1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st; int n=arr.size(); 
        vector<int> prevSm(n), nextSm(n);

        st.push(n-1);
        nextSm[n-1]=n;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) nextSm[i]=n;
            else nextSm[i]=st.top();
            
            st.push(i);
        }

        while(!st.empty()) 
            st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) prevSm[i]=-1;
            else prevSm[i]=st.top();
            st.push(i);
        }

         long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prevSm[i];   // choices on left
            long long right = nextSm[i] - i; // choices on right
            long long contrib = (arr[i] * left % MOD) * right % MOD;
            sum = (sum + contrib) % MOD;
        }

        return (int)sum;
    }
};