/*You are given an integer array arr of length n that represents a permutation of the integers 
in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. 
After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.

#Intution
The best way to do this is to think that as all the numbers are unique and we know the size of array, so we know all elements in the array. so, we know that in the sorted array arr[i] = i, it means that if we compute a running sum of elements in the array, then if at any moment, the sum = i*(i+1)/2, then we should make a partition at that point. continuing this process will give us the max no. of partitions.
like : 1, 0, 2, 3, 4
running sum : 1, 1, 3, 6, 10
i*(i+1)/2 : 0, 1, 3, 6, 10
for this, sum = i*(i+1)/2 condition is correct 4 times, so answer is 4 */

#include<vector>
using namespace std;

 class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int rs=0;
        int sum=0,k=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
           rs+=arr[i];
           sum=i*(i+1)/2;
           if(rs==sum){
            k++;
           }
        }
    
        return k;

    }
};