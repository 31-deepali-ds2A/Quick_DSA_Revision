#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<int> ans;

        // count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // check which appear more than n/3 times
        for (auto &p : freq) {
            if (p.second > n/3) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
