class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size(), score = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i] == '(') {
                st.push(score);
                score = 0;
            } 
            else {
                score = st.top() + max(2*score, 1);
                st.pop();
            }     
        }
        return score;
    }
};