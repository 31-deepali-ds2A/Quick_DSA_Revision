#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1]<b[1];
        });
        
        int ans=0;
       int last=intervals[0][1];

        for(int i=1;i<intervals.size();i++){

            if(intervals[i][0]<last){
                ans++;
                // overlapping
            }
            else{
                last=intervals[i][1];

            }
        }
        return ans;
    }
};