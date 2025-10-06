#include<vector>
#include<queue>
using namespace std;

// using indegree & outdegree
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> trustCount(n+1,0);

        for(auto& it:trust){
            trustCount[it[0]]--;
            trustCount[it[1]]++;
        }

        for(int i=1;i<=n;i++){
            if(trustCount[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};

// using 2-pointer
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < trust.size(); i++) {
            mat[trust[i][0]][trust[i][1]] = 1;
        }

        int left = 1, right = n;

        while (left < right) {
            if (mat[left][right] == 1)
                left++;
            else
                right--;
        }

        int candidate = left;

        // Verify the candidate
        for (int i = 1; i <= n; i++) {
            if (i == candidate) continue; // diag skip

            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};
