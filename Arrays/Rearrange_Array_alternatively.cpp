
// Given an array of positive integers. Your task is to rearrange the array elements alternatively i.e. first element should be the max value, the second should be the min value, the third should be the second max, the fourth should be the second min, and so on.
// Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.
// Examples:
// Input: arr[] = [1, 2, 3, 4, 5, 6]
// Output: [6, 1, 5, 2, 4, 3]

#include<vector>
#include<algorithm>
using namespace std;

//brute force
class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int> res;
        vector<int> maxVal,minVal;
       sort(arr.begin(),arr.end());
     
        for( int i=0;i<n/2;i++){
            maxVal.push_back(arr[n-i-1]);
            minVal.push_back(arr[i]);
        }
       
        for(int i=0;i<maxVal.size();i++){
            res.push_back(maxVal[i]);
            res.push_back(minVal[i]);
        }
        if (n % 2 != 0) {
            res.push_back(arr[n / 2]);
        }
        arr=res;
        
    }
};

//optimised (encoding)
class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int maxidx=n-1, minidx=0;
        int M=arr[maxidx]+1;
       
       for(int i=0;i<n;i++){
           if(i%2==0){
               arr[i]+=(arr[maxidx]%M)*M;
               maxidx--;
           }
           else{
               arr[i]+=(arr[minidx]%M)*M;
               minidx++;
           }
       }
       
       for(int i=0;i<n;i++){
           arr[i]=arr[i]/M;
       }
        
    }
};