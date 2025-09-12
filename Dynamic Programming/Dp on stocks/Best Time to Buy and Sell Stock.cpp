// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5


// brute-> using 2 loops check of each value ->O(n^2)

#include<vector>
using namespace std;

// Dp approach(optimized)--> O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            int curr=prices[i]-mini;
            profit=max(profit,curr);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};