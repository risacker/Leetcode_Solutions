class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> twosum;
        vector<int> ans;   
        for(int i = 0;i < n;i++){
            if(twosum.count(target - numbers[i]) > 0){
                ans.push_back(twosum[target - numbers[i]] + 1);
                ans.push_back(i + 1);
                return ans;
            }
            twosum[numbers[i]] = i;
         }
         return ans;  
       }
};