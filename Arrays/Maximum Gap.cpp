//brute force
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int mx=0;

        if(n<2) return mx;

        for(int i=1;i<n;i++){
            mx=max(mx,nums[i]-nums[i-1]);
        }
        return mx;
    }
};


// optimal-bucket sort

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());

        if(mx==mn) return 0;
        int bucketSize=max(1,(mx-mn)/(n-1));
        int bucketCount=(mx-mn)/bucketSize+1;

        vector<int> bucketMx(bucketCount,INT_MIN);
        vector<int> bucketMn(bucketCount,INT_MAX);
        vector<bool> used(bucketCount,false);

        // place number in buckets
        for(int num:nums){
            if(num==mn || num==mx) continue;
            int idx=(num-mn)/bucketSize;
            bucketMn[idx]=min(bucketMn[idx],num);
            bucketMx[idx]=max(bucketMx[idx],num);
            used[idx]=true;
        }

        // find max gap
        int prev=mn, ans=0;
        for(int i=0;i<bucketCount;i++){
            if(!used[i]) continue;
            ans=max(ans,bucketMn[i]-prev);
            prev=bucketMx[i];
        }
        ans=max(ans,mx-prev);

        return ans;
    }
};