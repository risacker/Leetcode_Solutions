class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {
        v = matrix;
        for (int i = 0;i < v.size();i++){
            for (int j = 1;j < v[0].size();j++){
                v[i][j] += v[i][j-1];
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for(int i = row1;i <= row2;i++){
            s += v[i][col2];
            if(col1 > 0){
                s -= v[i][col1-1];
            }
        }
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */