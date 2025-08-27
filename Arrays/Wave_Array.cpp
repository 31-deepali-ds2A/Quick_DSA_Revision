// Given an sorted array arr[] of integers. Sort the array into a wave-like array(In Place).
// In other words, arrange the elements into a sequence such that
// arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5] ..... and so on. 
// If there are multiple solutions, find the lexicographically smallest one.

#include<vector>
using namespace std;
class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        int n=arr.size();
        // code here
        for(int i=0;i<n-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
    }
};
