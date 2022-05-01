class Solution {
public:
    bool isHappy(int n) {
        int newNumber = 0;
        if (n == 1 || n== 7) 
            return true;
        else if (n < 10) 
            return false;
        while (n != 0) {
            newNumber += pow(n%10,2);
            n = n/10;
        }
        return isHappy(newNumber);
    }
};