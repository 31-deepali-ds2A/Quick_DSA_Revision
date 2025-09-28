#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


// brute force ->O(n log n)
class MedianFinder {
    vector<int> arr;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
         sort(arr.begin(),arr.end());
    }
    
    double findMedian() {
       
        int size=arr.size();
        double ans=0;

        if(size%2==0){
            int sum=arr[size/2]+arr[size/2-1];
           ans=sum/2.0;
            
        }
        else {
            ans=arr[size/2];
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 // optimal ->O(log n) using 2 heaps

 class MedianFinder {
    priority_queue<int> maxHeap; // left side
    priority_queue<int,vector<int>,greater<int>> minHeap; // right side
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num<=maxHeap.top()){
            maxHeap.push(num);
        }
        else
            minHeap.push(num);

        // balance sizes
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size())
            return (maxHeap.top()+minHeap.top())/2.0;
        return maxHeap.top();
    }
};