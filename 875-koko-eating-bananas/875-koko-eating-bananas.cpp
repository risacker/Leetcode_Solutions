class Solution {
public:
    bool can_eat_k(vector<int>& piles, int k, int h) {
        if (h <= piles.size()) return false;

        for (auto p : piles)
            h -= (p / k + (p % k != 0));

        return h >= 0;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end()), mid;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (can_eat_k(piles, mid, h)) hi = mid;
            else lo = mid + 1;
        }     
        return lo;
    }
};