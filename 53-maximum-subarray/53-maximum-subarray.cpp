class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            vector<int> subarray;
            int msf = nums[0], meh = 0;
  int s = 0;
  for (int i = 0; i < nums.size(); i++) {
    meh += nums[i];
    if (meh > msf) {
      subarray.clear();
      msf = meh;
      subarray.push_back(s);
      subarray.push_back(i);

    }
    if (meh < 0) {
      meh = 0;
      s = i + 1;

    }
  }

  return msf;
    }
};