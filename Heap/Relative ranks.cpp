

#include<queue>
#include<string>
#include<vector>
using namespace std;
//brute force

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<int> res(n);
        vector<string> ans;
        copy(score.begin(),score.end(),res.begin());
        sort(res.begin(),res.end(),greater<int>());
        
        for(int i=0;i<n;i++){
            if(score[i]==res[0]){
                ans.push_back("Gold Medal");
            }
            else if(score[i]==res[1]){
                ans.push_back("Silver Medal");
            }
            else if(score[i]==res[2]){
                ans.push_back("Bronze Medal");
            }
            else{
                for(int j=3;j<n;j++){
                    if(score[i]==res[j]){
                        ans.push_back(to_string(j+1));
                    }
                }
            }
        }
        return ans;
        
    }
};

// optimal

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
       int n=score.size();
        vector<string> ans(n);

        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        
        }
        int rank=1;
        while(!pq.empty()){
           int idx=pq.top().second;
            pq.pop();
        
            if(rank==3){
                ans[idx]="Bronze Medal";
                
            }
            else if(rank==2){
                ans[idx]="Silver Medal";
               
            }
            else if(rank==1){
                ans[idx]="Gold Medal";
               
            }
            else{
                ans[idx]=to_string(rank);
              
            }
             rank++;
        }
        return ans;
    }
};