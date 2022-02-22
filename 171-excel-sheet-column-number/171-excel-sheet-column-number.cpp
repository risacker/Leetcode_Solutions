class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long sum=0;
        long long mul=1;
        for(int i=columnTitle.size()-1;i>=0;i--){
            sum+=(mul*(columnTitle[i]-64));
            mul*=26;
        }
        return sum;
    }
};