class Solution {
public:
    int longestValidParentheses(string s) {
     stack<int> st;
        int counter = 0;
        int sum = 0;
        for(int i = 0; s[i]; i++){
            if(s[i] == '(')
                st.push(i);
           else if(s[i] == ')'){
                if(st.empty() || s[st.top()] == ')'){
                    st.push(i);
                    cout << s[i] << " ";
                }
                else {
                st.pop();  
                }
            }
        }
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        for(int i = 0; s[i]; i++){
            if(s[i] == '#'){
                sum = max(sum,counter);
                counter = 0;
            }
            else{
                counter++;
                sum = max(sum,counter);
            }
        }
        return sum;
    }
};