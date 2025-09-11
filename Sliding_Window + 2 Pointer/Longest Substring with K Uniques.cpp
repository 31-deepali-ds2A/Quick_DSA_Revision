#include<string>
#include<unordered_map>
using namespace std;


class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int maxlen=-1;
        unordered_map<int,int> mp;
        int count=0,left=0;
        
        for(int i=0;i<s.size();i++){
            
            mp[s[i]]++;
            
            while(mp.size()>k){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                
                left++;
                
            }
            if(mp.size()==k)
                    maxlen=max(i-left+1,maxlen);
        }
        return maxlen;
    }
};