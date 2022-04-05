class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);// creating N dynamic vectors which will be empty
        // transverse for N rows
        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);// for every row the no of cols = no of rows means resizing empty vector to a size i+1
            r[i][0] = r[i][i] = 1;// initializing 1st and last element to 1
          // linearly transversing from 1st col to the 2nd last col
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];// j-1 col value of prev row adding to it the jth col value of the prev row
        }   
        return r;// return pascal triangle 2D vector.
        
    }
};