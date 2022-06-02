class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int y = matrix.size(), x = matrix[0].size();
    vector<vector<int>> answer(x,vector<int>(y));
    for(int yy = 0; yy < y ; yy++)
      for(int xx = 0; xx < x; xx++)
        answer[xx][yy] = matrix[yy][xx];
    return answer;
    }
};