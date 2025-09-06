// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>
using namespace std;

//brute force
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int limit=accumulate(arr.begin(),arr.end(),0);
        int start=*max_element(arr.begin(),arr.end());
        if(arr.size()<k) return -1;
        
        for(int page=start;page<=limit;page++){
            if(canAllocate(arr,k,page)){
                return page;
            }
        }
        return -1;
    }
    
    bool canAllocate(vector<int>& arr,int k,int pages){
        int stCnt=1;
        int totalPage=0;
        
         
        for(int i=0;i<arr.size();i++){
            
            if(totalPage+arr[i]>pages){
                stCnt++;
                totalPage=arr[i];
            }
            else{
                
                totalPage+=arr[i];
            }
        }
        return stCnt<=k;
    }
};


//optimal
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int limit=accumulate(arr.begin(),arr.end(),0);
        int start=*max_element(arr.begin(),arr.end());
        if (arr.size() < k) return -1;
        int ans=-1;
        
       while(start<=limit){
           int mid=start+(limit-start)/2;
           
            if(canAllocate(arr,k,mid)){
                ans=mid;
                limit=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
    
    bool canAllocate(vector<int>& arr,int k,int pages){
        int stCnt=1;
        int totalPage=0;
        
         
        for(int i=0;i<arr.size();i++){
            
            if(totalPage+arr[i]>pages){
                stCnt++;
                totalPage=arr[i];
            }
            else{
                
                totalPage+=arr[i];
            }
        }
        return stCnt<=k;
    }
};