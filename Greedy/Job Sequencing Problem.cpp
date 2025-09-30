#include<vector>
#include<algorithm>
using namespace std;

// brute force -
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> jobs;
        int n=profit.size();
        
        for(int i=0;i<n;i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        
        sort(jobs.begin(),jobs.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first>b.first;
        });
        
        // max deadline
        int maxDeadline=0;
        for(auto& job:jobs){
            maxDeadline=max(maxDeadline,job.second);
        }
        
        vector<int> slots(maxDeadline+1,-1);
        int countJobs=0,maxProfit=0;
        
        for(auto& job:jobs){
            auto[profit,deadline]=job;
            
            for(int t=deadline;t>0;t--){
                if(slots[t]==-1){
                    slots[t]=profit;
                    countJobs++;
                    maxProfit+=profit;
                    break;
                }
            }
        }
        return {countJobs,maxProfit};
    }
};