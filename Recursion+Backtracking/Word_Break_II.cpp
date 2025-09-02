// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:
// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<string> temp;
        vector<string> ans;
        canBreak(s,st,temp,ans,0);
        return ans;

    }
    void canBreak(string s,unordered_set<string>& st,vector<string>& temp,vector<string>& ans,int idx){

        if(idx==s.size()){
            string t="";
            for(int j=0;j<temp.size();j++){
                if(j!=temp.size()-1){
                    t+=temp[j]+" ";
                }
               else t+=temp[j];
            }
            ans.push_back(t);
            return ;
        }

        string word;
        for(int i=idx;i<s.size();i++){
            word+=s[i];
            if(st.find(word)!=st.end()){
                temp.push_back(word);
                canBreak(s,st,temp,ans,i+1);
                temp.pop_back();
            }
        }
    }
};