class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int excluded = 0;
        int newIni = newInterval[0];
        int newFin = newInterval[1];
        for (int k = 0; k < intervals.size() - excluded; k++) {
            vector<int> interval = intervals[k];
            if (newInterval[1] >= interval[0] && newInterval[0] <= interval[1]) {
                if (newIni > interval[0])
                    newIni = interval[0];
                if (newFin < interval[1])
                    newFin = interval[1];
                interval = intervals[intervals.size() - 1 - excluded];
                intervals[intervals.size() - 1 - excluded] = intervals[k];
                intervals[k] = interval;
                excluded++;
                k--;
            }
        }
        if (excluded) {
            intervals[intervals.size() - excluded][0] = newIni;
            intervals[intervals.size() - excluded][1] = newFin;
            intervals.resize(intervals.size() - excluded + 1);
            sort(intervals.begin(), intervals.end());
            return intervals;
        }
        else {
            intervals.push_back({newIni, newFin});
            sort(intervals.begin(), intervals.end());
            return intervals;
        }
    }
};