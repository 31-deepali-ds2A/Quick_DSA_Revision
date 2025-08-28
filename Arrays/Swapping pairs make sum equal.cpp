 // Given two arrays of integers a[] and b[], the task is to check if a pair of values 
// (one value from each array) exists such that swapping the elements of the pair will make
//  the sum of two arrays equal.
#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<unordered_set>
using namespace std;


// If we swap a[i] and b[j]:
// newSumA = sumA - a[i] + b[j]
// newSumB = sumB - b[j] + a[i]

// We need newSumA == newSumB → gives a[i] - b[j] = (sumA - sumB)/2.

//brute force 
class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int sumA=accumulate(a.begin(),a.end(),0);
        int sumB=accumulate(b.begin(),b.end(),0);
        int diff=(sumA-sumB);
        
        if(diff%2!=0) return false;
        int target=diff/2;
        
        for(int x:a){
            for(int y:b){
                if(x-y==target){
                    return true;
                }
            }
        }
        return false;
    }
};

//optimised (hashing)
class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int sumA=accumulate(a.begin(),a.end(),0);
        int sumB=accumulate(b.begin(),b.end(),0);
        int diff=(sumA-sumB);
        
        if(diff%2!=0) return false;
        int target=diff/2;
        unordered_set<int> stB(b.begin(),b.end());
        
       
            for(int x:a){
                int y=x-target;
                if(stB.find(y)!=stB.end()){
                    return true;
                }
            }
        
        return false;
    }
};