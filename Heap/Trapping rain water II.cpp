#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Solution {
  #define  pip pair<int,pair<int,int>> 
public:
    bool isValid(int x,int y,int n,int m){
        return (x>=0 && x<n && y>=0 && y<m) ;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();

        if(n<3 || m<3) return 0; //invalid case

        vector<vector<int>> vis(n,vector<int>(m,0));
        priority_queue<pip,vector<pip>,greater<pip>> pq;

        // fill all boundary cells
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    pq.push({heightMap[i][j],{i,j}}); //{height,{row,col}} 
                    vis[i][j]=true; 
                }
            }
        }
        int level=0;
        int trappedWater=0;
        vector<int> dir={-1,0,1,0,-1};
        // apply bfs 

        while(!pq.empty()){

            int ht=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            level=max(level,ht); // update level

            for(int i=0;i<4;i++){
                int newR=r+dir[i];
                int newCol=c+dir[i+1];

                if(isValid(newR,newCol,n,m) && !vis[newR][newCol]){
                    vis[newR][newCol]=true;
                    pq.push({heightMap[newR][newCol],{newR,newCol}});
                    if(heightMap[newR][newCol]<level){
                        trappedWater+=(level-heightMap[newR][newCol]);
                    }
                }
            }
        }
        return trappedWater;

    }
};