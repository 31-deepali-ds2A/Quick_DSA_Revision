

#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
       
        int left=0;
        int right=arr.size()-1;
        int ans=0;
        
        while(left<right){
            int sum=arr[left]+arr[right];
            
            
            if(sum<target){
                left++;
            }
            else if (sum>target){
                right--;
            }
            else{
                int cnt1=0,cnt2=0;
                int first=arr[left], second=arr[right];
                
                while(left<=right && arr[left]==first){
                    left++;
                    cnt1++;
                }
                
                while(right>=left && arr[right]==second){
                    right--;
                    cnt2++;
                }
                if(first==second){
                    ans+=(cnt1*(cnt1-1))/2;
                }
                else ans+= cnt1*cnt2;
            }
            
        }
        
        
        return ans;
    }
};