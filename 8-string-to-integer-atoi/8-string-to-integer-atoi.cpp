class Solution {
public:
    int myAtoi(string s) {
        if(s == "") return 0;
        
        int i = 0;
        
        while(s[i] == ' ') {
            i++;
        }
        
        int sign = 1;
        
        if(s[i] == '-' || s[i] == '+') {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        
        long long int result = 0;
        
        while(i < s.length()) {
            if(!isdigit(s[i])) break;
            result = result * 10 + (s[i] - '0') * sign;
            if(result < INT_MIN) return INT_MIN;
            if(result > INT_MAX) return INT_MAX;
            i++;
        }
        
        return result;
    }
};