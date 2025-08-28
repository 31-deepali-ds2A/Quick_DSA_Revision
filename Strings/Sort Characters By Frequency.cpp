// Given a string s, sort it in decreasing order based on the frequency of the characters.
//  The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

#include<string>
#include<vector>
#include<unordered_map>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        string res="";
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        vector<pair<char,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](auto& a,auto& b){  // compartor function
            return a.second>b.second;
        });

        for(auto& it:vec){
            while(it.second>0){
                res+=it.first;
                it.second--;
                
            }

        }
        return res;
    }
};