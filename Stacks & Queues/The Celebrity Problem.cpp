// A celebrity is a person who is known to all but does not know anyone at a party. A party is 
// being organized by some people. A square matrix mat[][] of size n*n is used to represent
//  people at the party such that if an element of row i and column j is set to 1 it means ith 
// person knows jth person. You need to return the index of the celebrity in the party, if the 
// celebrity does not exist, return -1.

// Examples:

// Input: mat[][] = [[1, 1, 0],
//                 [0, 1, 0],
//                 [0, 1, 1]]
// Output: 1


#include<vector>
#include<stack>
using namespace std;

// brute force-> O(n^2) & O(n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();    
        vector<int> knowMe(n,0), iknow(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){ 
                if(i!=j && mat[i][j]==1) { // except diagonal
                iknow[i]++; // i knows j
                knowMe[j]++; // j knows i
                }
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(iknow[i]==0 && knowMe[i]==n-1) return i;
        }
        return -1;
    }
};

// optimal 1-> using stack-> O(n) & O(n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        stack<int> st;
        for(int i=0;i<n;i++) st.push(i);
        
        while(st.size()>1){
            int a=st.top();
            st.pop();
            
            int b=st.top();
            st.pop();
            
            if(mat[a][b]){ // a knows b-> a can't be celebrity
                st.push(b);
            }
            else st.push(a); // b knows a-> b can't be celebirty
        }
        int top=st.top();
        st.pop();
        
        for(int i=0;i<n;i++){
            if(i==top) continue; // if diagonal
            
            if(mat[top][i] || !mat[i][top]) return -1;
        }
        return top;
    }
};

// optimal 2-> using 2 pointer->O(n) & O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        int top=0, down=n-1;
        
        while(top<down){
            if(mat[top][down]==1){
                top++;
            }
            else if(mat[down][top]==1){
                down--;
            }
            else{
                top++;
                down--;
            }
            
        }
        if(top>down) top=down;
        
        for(int i=0;i<n;i++){
            if(i==top) continue; // if diagonal
            
            if(mat[top][i] || !mat[i][top]) return -1;
        }
        return top;
    }
};