class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {//2d matrix given
        
        int col0 = 1;//let's take column variable which is intitally = 1 means true
        int rows = matrix.size(), cols = matrix[0].size();//row and col size
        //linear transversal in matrix
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) //checking if the value at any of 0th col of given row i is 0 then set col0 to 0 means false 
                col0 = 0;
            for (int j = 1; j < cols; j++)//transverse rest of col starting from 1
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;// set leftmost and topmost to 0
         }
         //linear transversal from backwards in matrix
         for (int i = rows - 1; i >= 0; i--) {
             for (int j = cols - 1; j >= 1; j--)
                 if (matrix[i][0] == 0 || matrix[0][j] == 0)// if value of dummy array is 0 at any given index then set it as 0
                     matrix[i][j] = 0;
                 if (col0 == 0)//if col is false then set 0th col to be 0
                     matrix[i][0] = 0;
         }
     }
};
