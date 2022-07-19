class Solution {
public:
    int mySqrt(int x) {
         // solution 1
        // return sqrt(x);
       //}
      // solution 2
     // binary search
        long ans = -1;
        long lo = 0;
        long hi = x;
        while(lo <= hi){
            long mid = lo + (hi - lo) / 2;
            if(x == mid * mid)
                return (int)mid;
            else if(x > (mid * mid)){
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return (int)ans;
    }
};