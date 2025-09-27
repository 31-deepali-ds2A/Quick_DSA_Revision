#include<queue>
#include<vector>
using namespace std;

//brute O(log n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};

// heap-> O(n log n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       priority_queue<int> pq;
       for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
       }
       int ans=1;
       ans*=pq.top()-1;
       pq.pop();
       ans*=pq.top()-1;
     //  pq.pop();
       return ans;
    }
};

// O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int first = 0, second = 0;
        for (int x : nums) {
            if (x > first) { second = first; first = x; }
            else if (x > second) { second = x; }
        }
        return (first - 1) * (second - 1);

    }
};