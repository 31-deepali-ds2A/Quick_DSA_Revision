// Find all valid combinations of k numbers that sum up to n such that the following
// conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same 
//combination twice, and the combinations may be returned in any order.

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      
        vector<int> temp;
        vector<vector<int>> ans;
        possibleSum(k,n,temp,ans,1);
        return ans;

    }
    void possibleSum(int k,int n,vector<int>& temp,
                        vector<vector<int>>& ans,int idx){
       
        if(temp.size()==k && n==0){
            ans.push_back(temp);
            return ;
        }
        if(temp.size()>k || n<0) return;
        
        for(int i=idx;i<=9;i++){
            temp.push_back(i);
            possibleSum(k,n-i,temp,ans,i+1);
            temp.pop_back();
        }
       return;
    }

};