// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

// brute
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.size();
        int i=0,j=0;
        vector<int> ans;
        while(i<s.size()){
            string temp="";
            while(temp.size()<n){
                temp+=s[j];
                j++;
            }
            sort(temp.begin(),temp.end());
            if(temp==p){
                ans.push_back(i);
            }
            i++;
            j=i;
        }
        return ans;
        
    }
};

//optimal
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         if (s.size() < p.size()) return {};

        unordered_map<char,int> mp1,mp2;
        for(char c:p){
            mp1[c]++;
        }
        int size=p.size();
        vector<int> res; 

        for(int i=0;i<size;i++){
        mp2[s[i]]++;
            
        }
        if(mp1==mp2) res.push_back(0);

        for(int i=size;i<s.size();i++){

            mp2[s[i-size]]--; 
            mp2[s[i]]++;
         if(mp2[s[i-size]] == 0) {     // clean up
                mp2.erase(s[i-size]);
            }
            
            if(mp1==mp2){
                res.push_back(i-size+1);
            }
        }
        return res;
    }
};