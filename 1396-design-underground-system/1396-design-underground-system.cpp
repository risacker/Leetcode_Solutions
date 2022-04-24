class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    map<string,map<string, pair<int,int>>> dp;    
    map<int,pair<string,int>> customerCheckIn;
    map<int,pair<string,int>> customerCheckOut;
    
    void checkIn(int id, string stationName, int t) {
        customerCheckIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        customerCheckOut[id] = {stationName, t};
        auto checkInData = customerCheckIn[id];
        auto checkInStation = checkInData.first;
        auto duration = t - checkInData.second;
        auto &prev = dp[checkInStation][stationName];
        auto sum = prev.first, n = prev.second;
        prev = {(sum + duration), n+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto a = dp[startStation][endStation];
        return (double)a.first / a.second;  
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */