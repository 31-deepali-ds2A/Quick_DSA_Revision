/*Given an array arr and a number k. One can apply a swap operation on the array any number of
 times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum
  number of swaps required to bring all the numbers less than or equal to k together, i.e. 
  make them a contiguous subarray.*/

  # include<vector>
using namespace std;

  // Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        
        int n=arr.size();
        int start=n-1,cnt=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>k){
                start=i;
            }
            for(int j=start+1;j<n;j++){
                if(arr[j]<=k){
                    swap(arr[start],arr[j]);
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
