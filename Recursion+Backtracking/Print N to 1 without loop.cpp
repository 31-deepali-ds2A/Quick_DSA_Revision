
#include<iostream>
using namespace std;

class Solution {
  public:
    void printNos(int N) {
        // code here
        if(N<1) return;
        cout<<N<<" ";
        printNos(N-1);
    }
};

// 10 9 8 7 6 5 4 3 2 1 (N=10)