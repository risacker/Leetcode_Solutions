class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) 
            return 0;
        int ret = 1;
        int up = 0, down = 0, peak = 0;
        for(int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                peak = ++up;
                down = 0;
                ret += 1 + up;
            } 
            else if(ratings[i - 1] == ratings[i]){
                peak = up = down = 0;
                ret += 1 + up;
            } 
            else{
                up = 0;
                down++;
                ret += 1 + down + (peak >= down ? -1 : 0);
                }
            }
            return ret;
    }
};