#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); 
        possibleCombi(candidates, target, 0, temp, ans);
        return ans;
    }

    void possibleCombi(vector<int>& candidates, int target, int idx,
                       vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx >= candidates.size() || target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            // skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            
            if (candidates[i] > target) break; // prune

            temp.push_back(candidates[i]);
            possibleCombi(candidates, target - candidates[i], i + 1, temp, ans);
            temp.pop_back();
        }
    }
};
