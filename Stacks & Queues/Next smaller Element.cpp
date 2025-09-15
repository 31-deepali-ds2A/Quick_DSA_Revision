#include<vector>
#include<stack>
using namespace std;


// optimized
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n);
        
        ans[n-1]=-1;
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
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