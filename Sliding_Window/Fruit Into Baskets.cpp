// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//brute
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=INT_MIN;
        int cnt;

        for(int i=0;i<fruits.size();i++){
            unordered_set<int> st;
                cnt=0;
            for(int j=i;j<fruits.size();j++){
                if(st.count(fruits[j])>0){
                    cnt++;
                }
                else{
               if(st.size()<2){
                st.insert(fruits[j]);
                cnt++;
               }
               
               else break;
                }
               
            }
            maxlen=max(maxlen,cnt); 
        }
        return maxlen;
    }
};

//optimal
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int maxlen=INT_MIN;
        int left=0, right=0;
        unordered_map<int,int> mp;

        while(right<fruits.size()){
            mp[fruits[right]]++;

            while(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};