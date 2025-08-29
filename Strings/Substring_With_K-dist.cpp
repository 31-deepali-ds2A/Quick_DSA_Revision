// You are given a string s consisting of lowercase characters and an integer k, You have to count all possible substrings that have exactly k distinct characters.
// Examples :
// Input: s = "abc", k = 2
// Output: 2
// Explanation: Possible substrings are ["ab", "bc"]

#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//brute force (TLE)
class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here
        int n=s.size();
        int cnt=0;
        
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(mp.size()==k) cnt++;
            }
        }
        return cnt;
    }
};

// optimised (sliding window)
class Solution {
public:
    int atMostK(string& s, int k) {
        int n = s.size();
        int left = 0, cnt = 0;
        unordered_map<char,int> mp;

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;

            while (mp.size() > k) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }

            cnt += (right - left + 1);
        }
        return cnt;
    }

    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k-1);
    }
};
