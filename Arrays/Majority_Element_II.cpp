#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: HashMap counting
    vector<int> majorityElementHashMap(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num: nums) {
            mp[num]++;
        }
        int n = nums.size();
        int k = n / 3;
        vector<int> ans;
        for(auto it: mp) {
            if(it.second > k) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }

    // Approach 2: Sorting + counting
    vector<int> majorityElementSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = n / 3;
        vector<int> ans;

        for(int i = 0; i < n; ) {
            int j = i;
            while(j < n && nums[j] == nums[i]) {
                j++;
            }
            int freq = j - i;
            if(freq > k) {
                ans.push_back(nums[i]);
            }
            i = j; // move to next distinct element
        }
        return ans;
    }

    // Approach 3: Optimized Boyer–Moore Majority Vote
    vector<int> majorityElementOptimized(vector<int>& nums) {
        int cand1 = -1, cand2 = -1;
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();

        // First pass: Find candidates
        for(int num: nums) {
            if(num == cand1) cnt1++;
            else if(num == cand2) cnt2++;
            else if(cnt1 == 0) { cand1 = num; cnt1 = 1; }
            else if(cnt2 == 0) { cand2 = num; cnt2 = 1; }
            else { cnt1--; cnt2--; }
        }

        // Second pass: Verify counts
        cnt1 = 0, cnt2 = 0;
        for(int num: nums) {
            if(num == cand1) cnt1++;
            else if(num == cand2) cnt2++;
        }

        vector<int> ans;
        if(cnt1 > n/3) ans.push_back(cand1);
        if(cnt2 > n/3) ans.push_back(cand2);

        return ans;
    }
};

// Driver code

