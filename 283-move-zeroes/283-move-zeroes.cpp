class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        while(find(nums.begin() ,nums.end() ,0) != nums.end()) {
            cnt++;
            nums.erase(find(nums.begin() ,nums.end() ,0));
        }
        while(cnt) {
            nums.push_back(0);
            cnt--;
        }
    }
};