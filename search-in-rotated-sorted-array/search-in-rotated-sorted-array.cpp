class Solution {
public:
   int countRotations(vector<int> arr, int low, int high){
	if (high < low)
		return 0;
	if (high == low)
		return low;
	int mid = low + (high - low)/2; 

	if (mid < high && arr[mid+1] < arr[mid])
        return (mid+1);

	if (mid > low && arr[mid] < arr[mid - 1])
        return mid;

	if (arr[high] > arr[mid])
        return countRotations(arr, low, mid-1);
	return countRotations(arr, mid+1, high);
   }
    
    int binary(vector<int> nums, int target){
     int low = 0,high = nums.size()-1;
     while(low <= high){
         int mid = low + (high-low)/2;
         if(nums[mid] == target)
             return mid;
         else if(nums[mid]<target)
             low = mid+1;
         else
             high = mid-1;
     }   
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int i = countRotations(nums,0, nums.size()-1);
        vector<int> arr(nums.begin(), nums.begin()+i);
        int ans = binary(arr,target);
        if(ans != -1)
            return ans;
        vector<int> arr2(nums.begin()+i, nums.end());
        ans = binary(arr2,target);
        if(ans != -1)
            return ans+i;
        return -1;
    }
};