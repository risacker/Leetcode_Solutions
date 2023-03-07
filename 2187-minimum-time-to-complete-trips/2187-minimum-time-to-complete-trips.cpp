class Solution {
private:
    long long tripsTaken(vector<int> &time, long long sec){
        long long cnt = 0;
        for(auto it : time)
            cnt += sec/it;
        return cnt;
    }
     
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = 1e14;
        long long ans = high;
        while(low <= high){
            long long mid = (low + high)/2;
            if(tripsTaken(time,mid) >= totalTrips){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};