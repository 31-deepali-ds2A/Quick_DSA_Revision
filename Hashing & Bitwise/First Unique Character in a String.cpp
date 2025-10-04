#include<string>
#include<unordered_map>
#include<vector>
using namespace std;


// approach 1
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]={1,i};
            }
            else{
                mp[s[i]].first++;
            }
        }
    int ans=INT_MAX;
        for(auto& it:mp){
            if(it.second.first==1){
               ans = min(ans, it.second.second);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

//approach 2
class Solution {
public:
    int firstUniqChar(string s) {
         int arr[26]={0};
        int ans = -1;
        for(int i=0; i<s.length(); i++){
            int index = s[i]-'a';
            arr[index]++;
        }
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-'a'] == 1) return i; 
        }
        return ans;
    }
};