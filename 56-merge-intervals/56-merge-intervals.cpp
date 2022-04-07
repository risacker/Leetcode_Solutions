class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answers;
        vector<int> pairs;
        sort(intervals.begin(), intervals.end());
        int firstElement = intervals[0][0];
        int secElement = intervals[0][1];
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i][0]>secElement){
                pairs.push_back(firstElement);
                pairs.push_back(secElement);
                answers.push_back(pairs);
                firstElement = intervals[i][0];
                secElement = intervals[i][1];
                pairs.clear();
            }
            else{
                secElement = max(intervals[i][1], secElement);
            }
        }
        pairs.push_back(firstElement);
        pairs.push_back(secElement);
        answers.push_back(pairs);
        pairs.clear();
        return answers;
    }
};