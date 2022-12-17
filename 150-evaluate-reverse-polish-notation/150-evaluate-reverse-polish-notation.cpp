class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string n = tokens.back();
        tokens.pop_back();
        if(n != "+" && n != "-" && n != "*" && n != "/") 
            return stoi(n);
        else{
            long long b = evalRPN(tokens);
            long long a = evalRPN(tokens);
            if(n == "+") 
                return a + b;
            else if(n == "-") 
                return a - b;
            else if(n == "*") 
                return a * b;
            else 
                return a / b;
        }
    }
};