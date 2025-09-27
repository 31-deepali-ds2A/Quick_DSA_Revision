
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (auto &w : words) freq[w]++;

        // Min-heap: smaller frequency on top; for tie, lexicographically larger word on top
        auto cmp = [](pair<int,string> &a, pair<int,string> &b){
            if(a.first == b.first) return a.second < b.second; // smaller lex goes down
            return a.first > b.first; // smaller frequency on top
        };
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);

        // Keep heap of size k
        for (auto &it : freq) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();
        }

        // Extract elements from heap
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end()); // correct order: highest freq first
        return ans;
    }
};
