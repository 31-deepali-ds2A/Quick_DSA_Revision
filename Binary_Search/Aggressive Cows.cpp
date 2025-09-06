// You are given an array with unique elements of stalls[], which denote the positions of stalls.
//  You are also given an integer k which denotes the number of aggressive cows. The task is to 
//  assign stalls to k cows such that the minimum distance between any two of them is the maximum
//  possible.
// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3

//brute force

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int limit=stalls[n-1]-stalls[0];
        
        for(int dis=1;dis<=limit;dis++){
            
            if(canPlace(stalls,k,dis)==false){
                return dis-1;
            }
        }
        return limit;
    }
    
    bool canPlace(vector<int>& stalls,int k,int dis){
       
        int cnt=1;
        int lastPlaced=stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            
            if(stalls[i]-lastPlaced>=dis){
                lastPlaced=stalls[i];
                cnt++;
            }
            if(cnt>=k) return true;
        }
        return false;
    }
};

//optimal
class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int right=stalls[n-1]-stalls[0];
        int left=1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(canPlace(stalls,k,mid)){
                left=mid+1;
            }
            else right=mid-1;
        }
        return right;
    }
    
    bool canPlace(vector<int>& stalls,int k,int dis){
       
        int cnt=1;
        int lastPlaced=stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            
            if(stalls[i]-lastPlaced>=dis){
                lastPlaced=stalls[i];
                cnt++;
            }
            if(cnt>=k) return true;
        }
        return false;
    }
};