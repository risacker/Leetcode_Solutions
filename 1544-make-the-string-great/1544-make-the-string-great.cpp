class Solution {
public:
    string makeGood(string s) {
        if(s.empty()) 
            return s;
        for(int i = 0; i < s.size() - 1; ++i){
            if(abs(s[i] - s[i + 1]) == 32)
                return  makeGood(s.substr(0, i) + s.substr(i + 2));
        }
        return s;
    }
};