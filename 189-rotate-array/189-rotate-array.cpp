class Solution {
public:
     void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int j = k%n;
        vector a(nums.begin(), nums.begin()+n-j );
        nums.erase(nums.begin(), nums.end()-j);
        nums.insert(nums.end(),a.begin(),a.end()); 
    }
};