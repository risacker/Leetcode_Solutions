class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        else{
            int len = 0, l = x;
            int num = x, n = x;  
            while(l != 0){
                l /= 10;
                len++;  // get the length of the given integer
            }  
            while(num > 0){
                for(int i = 0; i < len - 1; i++){
                    n /= 10;    // get the first digit
                } 
                if(n != num % 10){
                    return false;   // first digit (n) not equal last digit (num%10)
                }  
                num -= n * pow(10, len-1); // to remove the first digit
                num /= 10; // to remove the last digit
                len -= 2; // reduce the length by the two removed digits
                n = num;    // n is to be the new filtered number
            }
            return true;
        }
    }
};