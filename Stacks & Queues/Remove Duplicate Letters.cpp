#include<string>
#include<vector>
#include<stack>
using namespace std;

//Given a string s, remove duplicate letters so that every letter appears once and only once. 
// You must make sure your result is the smallest in lexicographical order among all possible results.

// Example 1:

// Input: s = "bcabc"
// Output: "abc"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<bool> vis(26,false);
        stack<char> st;

        for(auto& c:s){
            freq[c-'a']++;
        }

        int n=s.size(); 
        for(auto& ch:s){
            
           freq[ch-'a']--;
           if(vis[ch-'a']) continue;
           vis[ch-'a']=true;

           while(!st.empty() && st.top()>ch && freq[st.top()-'a']>0){
                  vis[st.top()-'a'] = false;
                  st.pop();
           }
           st.push(ch);

        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};