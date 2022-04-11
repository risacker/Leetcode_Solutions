class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {   
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int count = 0;  
                if(i > 0 && j > 0 && board[i-1][j-1] % 2)
                    count++;
                if(i > 0 && board[i-1][j] % 2)
                    count++;
                if(i > 0 && j < board[0].size()-1 && board[i-1][j+1] % 2)
                    count++;
                if(j > 0 && board[i][j-1] % 2)
                    count++;
                if(j < board[0].size()-1 && board[i][j+1] % 2)
                    count++;
                if(i < board.size()-1 && j > 0 && board[i+1][j-1])
                    count++;
                if(i < board.size()-1 && board[i+1][j] % 2)
                    count++;
                if(i < board.size()-1 && j < board[0].size()-1 && board[i+1][j+1] % 2)
                    count++;
                if(count == 3)
                    board[i][j] += 2;
                else if(count == 2){
                    if(board[i][j])
                        board[i][j] += 2;
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
               board[i][j] /= 2; 
            }
        }
    }
};