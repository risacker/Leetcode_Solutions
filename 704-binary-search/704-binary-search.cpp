class Solution {
    int binary_search(vector<int> &nums, int target, int si, int ei){
        if(si >= ei && nums[si] != target)
            return -1;        
        int mid = (si + ei) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return binary_search(nums, target, si, mid - 1);
        else
            return binary_search(nums, target, mid + 1, ei);
    }
    
   public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size() - 1);
    }
};