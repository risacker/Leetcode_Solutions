class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0,j = 0,k = 0;
		vector<int> v(n+m);
		while(i < n && j < m){
			if(nums1[i] <= nums2[j])   
                v[k++] = nums1[i++];
			else    
                v[k++] = nums2[j++];
		}
		while(i < n)  
            v[k++] = nums1[i++];
		while(j < m)   
            v[k++] = nums2[j++];
		if((n+m) & 1)    
            return v[(n+m)/2];
		return (v[(n+m)/2] + v[(n+m)/2-1])/2.0;
    }
};