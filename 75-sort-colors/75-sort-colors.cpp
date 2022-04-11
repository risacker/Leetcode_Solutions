class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;// low pointer is pointing to start 
        int hi = nums.size() - 1;// high pointer is pointing to end
        int mid = 0;// mid pointer is pointing to start
        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
         
    }
};