// Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

#include<string>
#include<algorithm>
using namespace std;

// brute force-- TLE
class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int n=s.size();
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isPalindrome(temp)){
                    if(temp.size()>res.size()){
                        res=temp;
                    }
                }
            }
            temp="";
        }
        return res;
    }
    bool isPalindrome(string temp){
        if(temp.size()<=1) return true;
        int i=0, j=temp.size()-1;
        while(i<=j){
            if(temp[i]==temp[j]) {i++; j--;}
            else{return false;}
        }
        return true;
    }
};