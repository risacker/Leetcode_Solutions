class Solution {
public:
    int uniquePaths(int m, int n) {
        // create a matrix to store all possible path for a particular cell
        int mat[m][n];
        // path for 1st column element will always be 1
        // bec it can move only in downward direction in 1st col
        for(int i = 0;i < m;i++)
            mat[i][0] = 1;
        // path for 1st row will always be 1
        for(int i = 0;i < n;i++) 
            mat[0][i]=1;
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                // sum of left cell + sum of upper cell
                mat[i][j] = mat[i][j-1] + mat[i-1][j];
            }
        }
        // total number of ways to reach last cell
        return mat[m-1][n-1];
    }
};
