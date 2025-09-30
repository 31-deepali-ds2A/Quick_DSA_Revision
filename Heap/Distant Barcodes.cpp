#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> freq;
        for(int it:barcodes) freq[it]++;

        priority_queue<pair<int,int>> pq;

        for(auto& it:freq){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        pair<int,int> prev={0,-1};

        while(!pq.empty()){
            auto[count,val]=pq.top(); pq.pop();
            ans.push_back(val);
            count--;

            if(prev.first>0){
                pq.push(prev);
            }
            prev = {count, val};
        }
        return ans;
    }
};