// Given a string s, partition s such that every substring of the partition is a palindrome. 
// Return all possible palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        possiblePartition(s,temp,ans,0);
        return ans;
    }
    void possiblePartition(string s,vector<string>& temp,vector<vector<string>>& ans,int idx){

        if(idx==s.size()){
            ans.push_back(temp);
            return ;
        }
        string word="";

        for(int i=idx;i<s.size();i++){
            word+=s[i];

            if(isPlaindrome(word)){
                temp.push_back(word);
                 possiblePartition(s,temp,ans,i+1);
                 temp.pop_back();
            }
           
        }
    }
        bool isPlaindrome(string word){
            int i=0;
            int j=word.size()-1;
          

            while(i<=j){
                if(word[i]!=word[j]){
                    return false;
                }
                i++; j--;
            }
            return true;
        }
        
    
};