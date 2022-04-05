class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        int k = 5;
        while(n/k != 0){
            cnt += n/k;
            k *= 5;
        }
        return cnt;   
    }
};