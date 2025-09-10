// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4

#include<string>
#include<algorithm>
#include<map>
using namespace std;
//brute force

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxlen=0;
        

        int i=0;
        for(int i=0;i<n;i++){
            map<char,int> mp;
            int maxChar=0;
        for(int j=i;j<n;j++){
            mp[s[j]]++;
            maxChar=max(maxChar,mp[s[j]]);
            int size=j-i+1;
            int needed=size-maxChar;
            if(needed<=k){
                maxlen=max(maxlen,size);
            }
            
           
        }
        }
        return maxlen;
    }
};

// optimal
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxChar=0,maxlen=0;
        map<char,int> mp;

        int i=0;
        for(int j=0;j<n;j++){
            mp[s[j]]++;
            maxChar=max(maxChar,mp[s[j]]);

            while((j-i+1)-maxChar>k){
                mp[s[i]]--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
    }
};