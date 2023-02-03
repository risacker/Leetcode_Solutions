class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string *vec = new string[numRows];
        string str;
        int row = 0;
        int step = 1;
        for (int i = 0; i < s.size(); i++) {
            vec[row].push_back(s[i]);
            if (row == 0) {
                step = 1;
            } else if (row == numRows - 1) {
                step = -1;
            }
            row += step;
        }
        for (int i = 0; i < numRows; i++) {
            str += vec[i];
        }
        return str;
    }
};