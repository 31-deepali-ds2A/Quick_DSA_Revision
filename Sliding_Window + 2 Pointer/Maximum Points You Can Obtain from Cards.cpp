
// There are several cards arranged in a row, and each card has an associated number of points.
//  The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. 
// You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12

#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score=0;
        int totalScore=accumulate(cardPoints.begin(),
                        cardPoints.end(),0);
        int n=cardPoints.size();
        if(n==k) return totalScore;
        int len=n-k;
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=cardPoints[i];
        }
        score=max(score,totalScore-sum);

        for(int i=n-k;i<n;i++){
            sum+=cardPoints[i];
            sum-=cardPoints[i-(n-k)];
            score=max(score,totalScore-sum);
        }
        return score;
    }
};