class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>vec;
        sort(nums.begin(),nums.end());
        do{
            vec.push_back(nums);
         }while(next_permutation(nums.begin(),nums.end()));
        vec.erase(unique (vec.begin() , vec.end()), vec.end());
        return vec;
    }
};