class Solution {
public:
    bool isUgly(int num) {
        bool res = false;
        if(num == 0)
            return res;
        while(num%5 == 0){
            num /= 5;
        }
        while(num%3 == 0){
            num /= 3;
        }
        while(num%2 == 0){
            num /= 2;
        }
        if(num == 1)
            res = true;
         return res;
    }
   
};