// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra space.


#include<vector>
#include<algorithm>
using namespace std;

// brute force
 class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        sort(nums.begin(),nums.end());
        int maxGap=INT_MIN;
        for(int i=0;i<n-1;i++){
            int gap=abs(nums[i]-nums[i+1]);
            maxGap=max(maxGap,gap);
        }
        return maxGap;
    }
};

//using bucket sort

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        if (minVal == maxVal) return 0; // all numbers same

        // Step 2: Bucket size and count
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> bucketUsed(bucketCount, false);

        // Step 3: Distribute numbers
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            bucketUsed[idx] = true;
        }

        // Step 4: Find max gap between consecutive non-empty buckets
        int prevMax = minVal, maxGap = 0;
        for (int i = 0; i < bucketCount; i++) {
            if (!bucketUsed[i]) continue;
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};
