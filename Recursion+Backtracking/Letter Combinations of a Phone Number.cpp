class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
        vector<string> result;
        string curr;
        backtrack(0,digits,mp,curr,result);
        return result;
    }

private:
    void backtrack(int i,string& digits,unordered_map<char,string>& mp,
    string curr,vector<string>& result){

        if(i==digits.size()){
            result.push_back(curr);
            return ;
        }

        string letters=mp[digits[i]];

        // try each possible letter
        for(char c:letters){
            curr.push_back(c);
            backtrack(i+1,digits,mp,curr,result);
            curr.pop_back();
        }
    }
};