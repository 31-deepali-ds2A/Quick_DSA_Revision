// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

// Example 3:
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
    
       return canBreak(s,st,0);
        
    }
    bool canBreak(string s,unordered_set<string>& st,int idx){

        if(idx==s.size()){
            return true;
        }
        string word;
        for(int i=idx;i<s.size();i++){
            word+=s[i];
            if(st.find(word)!=st.end()){
               
                if(canBreak(s,st,i+1)) return true;
                
            }
        }
        return false;
    }
};