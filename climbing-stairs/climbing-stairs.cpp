class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
           return 1; 
        int a = 1, b = 1, c = 2; int cnt = 2; 
        while(cnt <= n){
            c = a+b; 
            a = b; 
            b = c;
            cnt++; 
        }
        return c; 
    }
};