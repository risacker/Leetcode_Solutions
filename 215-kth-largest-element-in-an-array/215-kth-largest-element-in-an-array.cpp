class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //soln 1:brute force
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];
        
        // soln 2: heap(pq)
        //asking for largest element so it will use min heap(refer:aditya verma{1&2} vdos)
        //declare min heap
        priority_queue<int, vector<int>, greater<int>>minh;
        int n = nums.size();//declaring the size
        for(int i = 0; i < n; i++){//trasversing the array
            minh.push(nums[i]);//pushing the elements into min heap
            if(minh.size() > k)//if size of min heap will exceed k then pop the element
                minh.pop();//popping the element which exceeds the size of k
        }
        return minh.top();//top of min heap will give kth largest element
    }
};