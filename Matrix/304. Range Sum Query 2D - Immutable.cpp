


// brute force

class NumMatrix {
   vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int r=row1;r<=row2;r++){
            for(int c=col1;c<=col2;c++){
                sum+= mat[r][c];
            }
        }
        return sum;

    }
};


// O(1) space
class NumMatrix {
    vector<vector<int>> prefix;  // 2D prefix sum array
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        
       
        prefix = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        
        // Build the prefix sum array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] 
                             + prefix[i][j-1] 
                             - prefix[i-1][j-1]; //duplicate removal
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return prefix[row2+1][col2+1] 
             - prefix[row1][col2+1] 
             - prefix[row2+1][col1] 
             + prefix[row1][col1];
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */