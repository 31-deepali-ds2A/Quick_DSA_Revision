// Given a string s with repeated characters, the task is to rearrange characters in a string such that no two adjacent characters are the same.
// Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them. If there is no possible solution, then print empty string ("").

#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

// heap O(n log n) & space O(n)
class Solution {
  public:
    string rearrangeString(string s) {
        // code here
        unordered_map<char,int> freq;
        for(auto& ch:s) freq[ch]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto& it:freq){
            pq.push({it.second,it.first});
        }
        
        string st="";
        pair<int,char> prev={-1,'#'};
        
        while(!pq.empty()){
            auto[count,curr]=pq.top();
            pq.pop();
            
            st+=curr;
            count--;
            
            if(prev.first>0) pq.push(prev);
            prev={count,curr};
        }
        if(st.size()!=s.size()) return "";
        return st;
    }
};