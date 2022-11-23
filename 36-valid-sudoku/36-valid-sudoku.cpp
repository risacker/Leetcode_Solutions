class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> mini_sq_location { {0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6} };
		
        vector<pair<int, int>> mini_sq_check { {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };

        unordered_set<int> tracker;

        for (int i = 0; i < 9; i++)
        {
            for (const auto &elem : board[i])
            {
                if (elem == '.') continue;
                int digit = elem - '0';
                if (tracker.find(digit) != tracker.end()) 
                    return false;
                tracker.insert(digit);
            }
            tracker.clear();

            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.') 
                    continue;

                int digit = board[j][i] - '0';
                if (tracker.find(digit) != tracker.end()) 
                    return false;

                tracker.insert(digit);
            }
            tracker.clear();
            auto[x, y] = mini_sq_location[i];
            for (const auto &elem : mini_sq_check)
            {
                auto[p, q] = elem;
				
                if (board[x + p][y + q] == '.') continue;

                int digit = board[x + p][y + q] - '0';
				
                if (tracker.find(digit) != tracker.end()) return false;

                tracker.insert(digit);
            }
            tracker.clear();
			
        }
        
		
        return true;
    }
};