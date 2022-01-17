class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);
        for(int i = 0; i < k; i++)
            ans.push_back(points[i]);
        return ans;
    }
    static bool comp(vector<int> &a, vector<int> &b){
        return sqrt(pow(a[0],2)+pow(a[1],2)) < sqrt(pow(b[0],2)+pow(b[1],2));
    }
};