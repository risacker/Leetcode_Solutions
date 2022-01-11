class Solution {
public:    

    int reverse(int n) {
        long a = 0;
        while (n) {
            a = a*10 + n%10;
            n /= 10;  
        }
        return a<INT_MIN || a>INT_MAX ? 0 : a;
    }
};