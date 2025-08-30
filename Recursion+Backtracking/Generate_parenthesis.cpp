#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        build(n,0,0,"",res);
        return res;
    }
    void build(int n,int open,int close,string curr,vector<string>& res){
        if(open==n && close==n){
            res.push_back(curr);
            return ;
        }
        if(open<n){
            build(n,open+1,close,curr+'(',res);
        }
        if(close<open){
            build(n,open,close+1,curr+')',res);
        }
    }
};