
/*We have N persons sitting on a round table. Any person can do a handshake with any other person.

     1
2         3
     4
Handshake with 2-3 and 1-4 will cause cross.
In how many ways these N people can make handshakes so that no two handshakes cross each other. N would be even. */

// recursion Tree
/*nonCrossing(6)
 ├── [j=2] → nonCrossing(0) * nonCrossing(4)
 │               └── nonCrossing(4)
 │                    ├── [j=2] → nonCrossing(0) * nonCrossing(2)
 │                    └── [j=4] → nonCrossing(2) * nonCrossing(0)
 │
 ├── [j=4] → nonCrossing(2) * nonCrossing(2)
 │
 └── [j=6] → nonCrossing(4) * nonCrossing(0)
                 └── nonCrossing(4)
                      ├── [j=2] → nonCrossing(0) * nonCrossing(2)
                      └── [j=4] → nonCrossing(2) * nonCrossing(0) */

// Catalan number

class Solution {
  public:
    int count(int N) {
        // code here
        if(N==0) return 1;
        if(N==2) return 1;
        
        int ways=0;
        
        for(int j=2;j<=N;j+=2){
            int left=j-2;
            int right=N-j;
            ways+= count(left)*count(right);
        }
        return ways;
    }
};