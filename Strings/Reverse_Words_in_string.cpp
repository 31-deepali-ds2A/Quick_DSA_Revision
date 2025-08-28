// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"

#include<string>
#include<stack>
using namespace std;

// brute force
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
       
        string res="";
        string temp="";

        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(!temp.empty()){
                    reverse(temp.begin(),temp.end());
                    if (!res.empty()) res += " ";
                    res+=temp;
                    
                    temp="";
                }
            
            }
            else
                temp+=s[i];
        }
       if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if (!res.empty()) res += " ";
            res += temp;
        }
        return res;
    }
};

// stack solution

class Solution {
public:
    string reverseWords(string s) {
        string res="", temp="";
        stack<char> st;
        int n=s.size();

        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(!st.empty()){
                    while(!st.empty()){
                        temp+=st.top();
                        st.pop();
                    }
                    if(!res.empty()) res+=" ";
                    res+=temp;
                    temp="";
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        if(!res.empty() && !temp.empty()) res+=" ";
        res+=temp;

        return res;
    }
};