// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.


#include<vector>
#include<algorithm>
using namespace std;

// brute force

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area=0;
        int n=height.size();
        int left=0,right=n-1;

        while(left<right){
            int h=min(height[left],height[right]);
            int currarea=h*(right-left);
            area=max(area,currarea);
            if(height[left]<height[right]){
                left++;
            }
            else if(height[right]<=height[left]){
                right--;
            }
            
        }
        return area;
    }
};



// optimal(move to the lowest side taking 2 pointer)
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area=0;
        int n=height.size();
        int left=0,right=n-1;

        while(left<right){
            int h=min(height[left],height[right]);
            int currarea=h*(right-left);
            area=max(area,currarea);

            if(height[left]<height[right]){
                left++;
            }
            else if(height[right]<=height[left]){
                right--;
            }
            
        }
        return area;
    }
};