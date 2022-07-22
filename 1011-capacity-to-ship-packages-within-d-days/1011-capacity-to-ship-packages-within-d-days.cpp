class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);  
        while(right > left){
            int mid = (right + left) / 2, time = 0;
            int temp = 0;
            for(int i = 0; i < n; ++ i){
                temp += weights[i];
                if(temp > mid){
                    time ++;
                    temp = weights[i];
                }
            }
            if(temp != 0) 
                time ++;
            if(time > days)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};