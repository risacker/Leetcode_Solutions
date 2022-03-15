class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int open = 0;  
        for(char ch : s) {
            if(ch == '(') 
                open++;
            else if(ch == ')') {
                if(open == 0) 
                    continue;
                open--;
            }
            res += ch;
        }
        string ans;
        for(int i = res.size()-1; i>= 0; i--) {
            if(res[i] == '(' && open-- > 0)
                continue;
            ans += res[i];
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};