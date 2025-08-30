// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

#include<vector>
using namespace std;

 class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        rev(s,i,j);
    }
    void rev(vector<char>& s, int i,int j){
        if(i>=j) return ;
        swap(s[i],s[j]);
        rev(s,i+1,j-1);
    }
};