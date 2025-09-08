#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // sliding window
        int k=s1.size();
        int n=s2.size();
        if(k>n) return false;

        unordered_map<char,int> freq1,freq2;

        for(char ch:s1){
            freq1[ch]++;
        }

        for(int i=0;i<k;i++){
            freq2[s2[i]]++;
        }
        if(freq1==freq2) return true;

        for(int i=k;i<n;i++){
            freq2[s2[i]]++;
            freq2[s2[i-k]]--;
            if(freq2[s2[i-k]]==0){
                freq2.erase(s2[i-k]);
            }
            if(freq1==freq2) return true;
        }
        return false;

    }
};