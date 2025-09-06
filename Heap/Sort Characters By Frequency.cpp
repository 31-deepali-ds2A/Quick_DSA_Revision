#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        string t="";

        for(auto& it:s){
            mp[it]++;
        }
    priority_queue<pair<int,char>> pq; //max-heap

        for(auto& it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            int freq=pq.top().first;
            char ch=pq.top().second;
            while(freq>0){
                t+=ch;
                freq--;
            }
            pq.pop();
        }
    
    return t;
    }
};