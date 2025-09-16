#include<vector>
#include<stack>
using namespace std;

// Input: nums = [1,2,1] , circular array
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i=0;i<n*2;i++){
            int idx=i%n;

            while(!st.empty() && nums[st.top()]<nums[idx]){
                ans[st.top()]=nums[idx];
                st.pop();
            }
            if(i<n){
                st.push(idx);
            }
        }
        return ans;
    }
};