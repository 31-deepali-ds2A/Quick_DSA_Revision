
// You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.

// In one operation you can choose any subarray from initial and increment each value by one.
// Return the minimum number of operations to form a target array from initial.
// The test cases are generated so that the answer fits in a 32-bit integer.

 

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        // if curr> prev :: curr-prev no. of steps
        // curr<=prev then already done

        int steps=0;
        int prev=0;
        int n=target.size();
        for(int i=0;i<n;i++){
            int curr=target[i];
            if(curr > prev){
                steps+=(curr-prev);
            }
            prev=curr;
        }
        return steps;
    }
};