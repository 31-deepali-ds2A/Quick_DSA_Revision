#include<vector>
#include<stack>
#include<string>
using namespace std;

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle 
// containing only 1's and return its area.

//-->> conversion of largest rectangle in a histogram problem

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> preSum(n,vector<int>(m));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                int val = matrix[i][j] - '0';
                sum+=val;
                if(matrix[i][j]=='0') sum=0;

                preSum[i][j]=sum;
            }
        }

        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,lhist(preSum[i])); // compute for each row and find max
        }
        return maxArea;
    }

    // fun of largest rectangle in histogram

    int lhist(vector<int>& preSum){ // each row is passed in a function
        int maxArea=0;
        int n=preSum.size();
        vector<int> ns(n),ps(n);
        stack<int> st;

        // find next smaller
        st.push(n-1);
        ns[n-1]=n;

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && preSum[st.top()]>preSum[i]){
                st.pop();
            }
            if(st.empty()) ns[i]=n;
            else ns[i]=st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop(); // clear stack

        // find prev smaller
        for(int i=0;i<n;i++){
            while(!st.empty() && preSum[st.top()]>=preSum[i]) st.pop();
            if(st.empty()) ps[i]=-1;
            else ps[i]=st.top();
            st.push(i);
        }

        // find max area
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,(ns[i]-ps[i]-1)*preSum[i]);
        }
        return maxArea;

    }
};