#include<vector>
#include<math.h>
using namespace std;

// brute force

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxSum=arr[0];
        
        for(int i=0;i<n;i++){
            int curr=0;
            
            for(int j=0;j<n;j++){
                int idx=(i+j)%n;
                curr+=arr[idx];
                maxSum=max(maxSum,curr);
            }
            
        }
        return maxSum;
    }
};

// optimized(kadane's algorithm)

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxSum=arr[0],minSum=arr[0];
        int currMax=arr[0], currMin=arr[0];
        int total=arr[0];
        
        for(int i=1;i<n;i++){
            currMax=max(currMax+arr[i],arr[i]);
            maxSum=max(maxSum,currMax);
            
            currMin=min(currMin+arr[i],arr[i]);
            minSum=min(minSum,currMin);
            
            total+=arr[i];
        }
        if(maxSum<0) return maxSum;
        return max(maxSum,total-minSum);
        
        
        return maxSum;
    }
};