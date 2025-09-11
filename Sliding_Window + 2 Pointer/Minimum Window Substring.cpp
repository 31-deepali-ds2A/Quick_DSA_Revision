// Given two strings s and t of lengths m and n respectively, return the minimum window substring
//  of s such that every character in t (including duplicates) is included in the window. If there 
//  is no such substring, return the empty string "".
// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// brute force

class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = s.size() + 1;
        string ans = "";

        // frequency map for t
        unordered_map<char,int> freqT;
        for(char c : t) freqT[c]++;

        for(int i = 0; i < s.size(); i++) {
            string word = "";
            unordered_map<char,int> freqW;

            for(int j = i; j < s.size(); j++) {
                word += s[j];
                freqW[s[j]]++;

                if(word.size() >= t.size()) {
                    bool ok = true;
                    for(auto &p : freqT) {
                        if(freqW[p.first] < p.second) { // not enough chars
                            ok = false;
                            break;
                        }
                    }
                    if(ok && (int)word.size() < minlen) {
                        minlen = word.size();
                        ans = word;
                    }
                }
            }
        }
        return ans;
    }
};

// optimized (sliding_window)
class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        

        // frequency map for t
        unordered_map<char,int> freqT,freqW;
        for(char c : t) freqT[c]++;
        
        int left=0, right=0;
        int req=freqT.size();
        int start=0,formed=0;

        while( right<s.size()){
           char ch=s[right];
            freqW[ch]++;

            if(freqT.count(ch) &&freqT[ch]==freqW[ch] ){
                formed++;
            }
            // start shrinking window
            while(left<=right && formed==req){
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char leftChar = s[left];
                freqW[leftChar]--;
                if (freqT.count(leftChar) && freqW[leftChar] < freqT[leftChar]) {
                    formed--;
                }
                left++;
            }
            // ---- til here
            right++;
            }
       return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};

// optimal
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int need[256] = {0};  
        for (char c : t) {
            need[c]++;
        }

        int left = 0, count = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            // Include current char
            if (--need[s[right]] >= 0) {
                count++;  // valid char from t included
            }

          
            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Try shrinking
                if (++need[s[left]] > 0) {
                    count--;  // lost a required char
                }
                left++;
            }
        }

    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};


