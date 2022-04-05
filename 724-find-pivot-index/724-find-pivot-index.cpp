class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int totalSum = accumulate(nums.begin(), nums.end(), 0); //This function returns the sum of all the values lying in a range between [first, last) with the variable sum. 
        int sum = 0; 
        for(int i = 0; i < nums.size(); ++i){
            if(2 * sum + nums[i] == totalSum)
                return i;
            sum += nums[i];
        }
        return -1; 
    }
};