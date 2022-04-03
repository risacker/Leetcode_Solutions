class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0;
        do{
            if(i == 1)
                break;
            i++;
        } while (next_permutation(nums.begin(), nums.end()));
        if(i != 1){
            sort(nums.begin() , nums.end());
        }
    }
};