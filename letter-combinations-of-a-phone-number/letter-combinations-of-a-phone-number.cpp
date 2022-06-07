class Solution {
public:
    unordered_map<char, string> dict;
    vector<string> res;
    int len;
    vector<string> letterCombinations(string digits) {
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";      
        len = digits.size();
        string track;
        backtrack(digits, track, 0);
        return res;
    }
    
    void backtrack(string& digits, string& track, int ind) {
        for (int i = ind; i < len; ++i) {
            for (char d : dict[digits[i]]) {
                track.push_back(d);
                if (track.size() == len) {
                    res.push_back(track);
                } 
                else {
                    backtrack(digits, track, i + 1);
                }
                track.pop_back();
            }
        }
    }
};