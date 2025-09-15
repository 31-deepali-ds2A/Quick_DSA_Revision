#include<vector>
#include<queue>

using namespace std;


// brute force--> O(n^2 log n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size()>1){
            int n=stones.size();
            sort(stones.begin(),stones.end());
            int stone1=stones[n-1];
            int stone2=stones[n-2];

            if(stone1==stone2){
                stones.pop_back();
                stones.pop_back();
            }
            else{
                stones.pop_back();
                stones.pop_back();
                stones.push_back(stone1-stone2);
            }
        }
        return stones.size()>0 ? stones[0]:0;
    }
};

// optimized
class Solution {
public: // O(nlog n)
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        
        while(pq.size()>1){
           int stone1=pq.top();
           pq.pop();
           int stone2=pq.top();
           pq.pop();
           if(stone1!=stone2)
            pq.push(stone1-stone2);
        }
        return pq.size()>0 ? pq.top():0;

    }
};