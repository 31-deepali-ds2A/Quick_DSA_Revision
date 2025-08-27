/*You are given a 2D 0-indexed integer array dimensions.

For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.

Return the area of the rectangle having the longest diagonal. If there are multiple
 rectangles with the longest diagonal, return the area of the rectangle having the maximum
  area. */

# include<vector>
using namespace std;
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int maxDiagSq=0,maxArea=0;

        for(int i=0;i<n;i++){
            int width=dimensions[i][1];
            int len=dimensions[i][0];
            int diagSq=(len*len + width*width);
            int area=len*width;
            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }
        return maxArea;



    }
};