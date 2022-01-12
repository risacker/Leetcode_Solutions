class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;    
        if (s.length() == 1)
            return false;
        std::stack<char> st;            
        for (char& ch : s) {
            if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty())
                    return false;
                if ((ch == ')' && st.top() != '(') || (ch == '}' && st.top() != '{') || (ch == ']' && st.top() != '['))
                    return false;
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        return st.empty();
        
    }
};