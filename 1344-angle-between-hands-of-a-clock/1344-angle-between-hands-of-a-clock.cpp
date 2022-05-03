class Solution {
public:
    double angleClock(int hour, int minutes) {
         if(hour==12)
            hour=0;
         double hh = hour*30 + minutes/2.0;
         double mm = minutes * 6;  
         return min(abs(mm - hh), 360 - abs(mm - hh));
    }
};