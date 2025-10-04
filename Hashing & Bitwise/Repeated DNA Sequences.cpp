#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string> ans;
        int n=s.size();
        string temp="";

        for(int i=0;i<=n-10;i++){
            string temp=s.substr(i,10);
            mp[temp]++;
        }

        for(auto& st:mp){
            if(st.second>1){
                ans.push_back(st.first);
            }
        }
        return ans;
       
    }
};