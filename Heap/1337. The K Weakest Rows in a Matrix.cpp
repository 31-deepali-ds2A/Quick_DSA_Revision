#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>>> minHeap;

        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    sum++;
                }
            }
            minHeap.push({sum,i});
        }
    
    vector<int> ans;
    while(k--){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;
}
};