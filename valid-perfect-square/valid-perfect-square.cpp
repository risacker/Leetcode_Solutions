class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 0;pow(i, 2) <= num;i++)
            if(pow(i,2) == num)
                return true;
        return false;
    }
};