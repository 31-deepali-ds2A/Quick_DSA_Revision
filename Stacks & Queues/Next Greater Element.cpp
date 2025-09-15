#include<stack>
#include<vector>
using namespace std;


// brute force
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            bool found=false;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    ans[i]=arr[j];
                    found=true;
                    break;
                }
            }
            if(!found) ans[i]=-1;
        }
        return ans;
    }
};

// using stack
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n);
        
        stack<int> st;
        
        ans[n-1]=-1;
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--){
            
           
            while(!st.empty() && st.top()<=arr[i]){
               st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            
             st.push(arr[i]);
            
        }
        return ans;
        }
    
};