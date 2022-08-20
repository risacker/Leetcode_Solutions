class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // adding target station
        stations.push_back({target, 0});
        // support variables
        int res = 0, pos = startFuel, currStationPos = 0, len = stations.size();
        auto nextStation = stations[0];
        priority_queue<int> fuelOptions;
        // computing the path to target
        while(pos < target) {
            // keeping track of the stations encountered
            while(nextStation[0] <= pos && currStationPos < len) {
                fuelOptions.push(nextStation[1]);
                nextStation = stations[++currStationPos];
            }
            // adding fuel as needed to reach the next station from here
            while(nextStation[0] > pos && fuelOptions.size()) {
                pos += fuelOptions.top();
                fuelOptions.pop();
                res++;
            }
            // checking if we cannot reach the next station from here
            if(nextStation[0] > pos) 
                return -1;
        }
        return res;
    }
};