// Input : abc
// Output : a ab abc ac b bc c

#include<string>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    vector<string> powerSet(string s) {
        vector<string> ans;
        string temp = "";
        sort(s.begin(), s.end()); // ensure lexicographic order
        generateSubsets(s, 0, temp, ans);
        sort(ans.begin(), ans.end()); // final sort
        return ans;
    }

    void generateSubsets(string& s, int idx, string& temp, vector<string>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        // Choice 1: include current character
        temp.push_back(s[idx]);
        generateSubsets(s, idx + 1, temp, ans);
        temp.pop_back();

        // Choice 2: exclude current character
        generateSubsets(s, idx + 1, temp, ans);
    }
};


