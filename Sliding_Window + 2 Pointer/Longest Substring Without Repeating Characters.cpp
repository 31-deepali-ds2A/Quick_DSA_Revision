// Input: s = "abcabcbb"
// Output: 3

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

// 2-pointer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0, j=0;
        int maxLen=0;
        unordered_set<char> st;

        while(i<n && j<n){

            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                maxLen=max(maxLen,j-i+1);
                  j++;
            }
            else{
                    st.erase(s[i]);
                    i++;
            } 
        }
        return maxLen;
    }
};