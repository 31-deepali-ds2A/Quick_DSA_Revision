#include<queue>
#include<vector>
using namespace std;

// Time: O(n log k) → push/pop for n points, heap size ≤ k
// Space: O(k) → heap stores at most k elements

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq; // max-heap

        for(int i=0;i<points.size();i++){

           int dis = points[i][0] * points[i][0] + 
           points[i][1] * points[i][1];

            pq.push({dis,i});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};