
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
       
        int n=start.size();
        int ans=1;
        vector<vector<int>> meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({start[i],end[i]});
        }
        
        sort(meetings.begin(),meetings.end(),[](const vector<int>& a,
        const vector<int>& b){
            return a[1]<b[1];
        });
        
         int last=meetings[0][1];
         
        for (int i = 1; i < n; i++) {
            if (meetings[i][0] > last) {  // Non-overlapping
                ans++;
                last= meetings[i][1];
            }
        }
        return ans;
        

    }
};