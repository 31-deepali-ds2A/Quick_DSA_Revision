// A valid IP address consists of exactly four integers separated by single dots. Each integer 
// is between 0 and 255 (inclusive) and cannot have leading zeros.
// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", 
// "192.168.1.312" and "192.168@1.1" are invalid IP addresses.


#include<string>
#include<unordered_set>
#include<vector>
using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string temp="";
        vector<string> ans;
        possibleIp(s,ans,0,0,temp);
        return ans;
    }
    void possibleIp(string s,vector<string>& ans,int idx,int parts,string& temp){
        if(parts==4 && idx==s.size()){
            ans.push_back(temp);
            return;
        }
    if (parts == 4 || idx == s.size()) return;

        string word="";
        int lenBefore=temp.size();

        for(int i=idx;i<s.size();i++){
            word+=s[i];
            int val=stoi(word);

            if(word.size()>1 && word[0]=='0') break;

            if(val>=0 && val<=255){
                 if (!temp.empty()) temp.push_back('.');

                temp+=word;
                possibleIp(s,ans,i+1,parts+1,temp);
                 temp.resize(lenBefore);
            }
            else{
                break;
            }
        }

    }
};