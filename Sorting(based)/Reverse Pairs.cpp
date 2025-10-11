//brute force
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int pairs=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if ((long long)nums[i] > 2LL * nums[j]) {
                        pairs++;
                    }
            }
        }
        return pairs;
    }
};


// optimized - using merge sort
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }

private:
    int mergeSort(vector<int>& nums,int low,int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid=(low)+(high-low)/2;
        cnt+=mergeSort(nums,low,mid);
        cnt+=mergeSort(nums,mid+1,high);
        cnt+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);

        return cnt;
    }

    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int> temp;
        int left=low, right=mid+1;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else temp.push_back(nums[right++]);
        }

        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }

    }

    int countPairs(vector<int>& arr,int low,int mid,int high){
        int right=mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)arr[i]> 2LL* arr[right]){
                right++;
            }
            cnt+=(right-(mid+1));

        }
        return cnt;
    }
};