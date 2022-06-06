class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][10];
        bool col[9][10];
        bool mat[3][3][10];
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 10;j++){
                row[i][j] = false;
                col[i][j] = false;
            }
        }
        
        for(int i = 0;i < 9;i++)
            for(int j = 0;j < 9;j++)
                for(int k = 0;k < 10;k++)
                    mat[i/3][j/3][k] = false;
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.') 
                    continue;
                int num = board[i][j] - '0';
                row[i][num] = true;
                col[j][num] = true;
                mat[i/3][j/3][num] = true;
            }
        }
        
        dfs(board, 0, 0, row, col, mat);
    }
    
    bool dfs(vector<vector<char>>& board, int r, int c,  bool row[9][10], bool col[9][10], bool mat[3][3][10]){
        if(c == board[0].size()){
            c = 0;
            r++;
            if(r == board.size())
                return true;
        }
        
        if(board[r][c] == '.'){
            for(int num = 1;num <= 9;num++){
                if(!(row[r][num] || col[c][num] || mat[r/3][c/3][num])){
                    row[r][num] = true;
                    col[c][num] = true;
                    mat[r/3][c/3][num] = true;
                    board[r][c] = num + 48;
                    if(dfs(board, r, c+1, row, col, mat))
                        return true;
                    board[r][c] = '.';
                    row[r][num] = false;
                    col[c][num] = false;
                    mat[r/3][c/3][num] = false;
                }
            }
        }
        
        else
            return dfs(board, r, c+1, row, col, mat);
        return false;
    }
};