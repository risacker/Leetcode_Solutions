class Solution {
public:
    static bool comp(vector<int>&x, vector<int>&y){
        return (x[1] > y[1]);        
    } 
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),comp);
        int n = boxTypes.size();
        int count=0;
        for(int i = 0; i < n;i++){
            int boxCount = min(boxTypes[i][0], truckSize);
            count += boxCount*boxTypes[i][1];
            truckSize -= boxCount;    
            if(truckSize == 0)
                break;
        }
        return count;
    }
};