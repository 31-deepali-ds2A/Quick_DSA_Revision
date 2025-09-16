#include<stack>
#include<vector>
using namespace std;

//Input: heights = [2,1,5,6,2,3]
//Output: 10

// brute force --> O(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxArea=0;
        

        for(int i=0;i<heights.size();i++){
            int minheight=INT_MAX;
            for(int j=i;j<heights.size();j++){
                minheight=min(minheight,heights[j]);
                maxArea=max(maxArea,(j-i+1)*minheight);
            }
        }
        return maxArea;
    }
};

// optimized 1 --> O(n) space-> O(3*n);

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        stack<int> st;
        vector<int> ls(n),rs(n);

        // find the right smaller
        st.push(n-1);
        rs[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                rs[i]=n;
            }
            else{
                rs[i]=st.top();
            }
            st.push(i);
        }

    // clear stack 
       while (!st.empty())
        st.pop();

// find left smaller
        st.push(0);
        ls[0]=-1;

        for(int i=1;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ls[i]=-1;
            }
            else{
                ls[i]=st.top();
            }
            st.push(i);
        }

        for(int i=0;i<heights.size();i++){
            int area=(rs[i]-ls[i]-1)*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};

// optimal
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;

        int maxArea=0;
        int n=heights.size();

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int h=heights[st.top()];
                st.pop();
                int width;

                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                maxArea=max(maxArea,width*h);
            }
            st.push(i);
        }
        return maxArea;
    }
};
