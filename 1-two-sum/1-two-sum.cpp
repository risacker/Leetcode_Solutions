class Solution {
 public:
      vector<int> twoSum(vector<int>& nums, int target) {
          int sum = 0;
          bool got = false;
          int n = nums.size();
          vector<int> v;
          for(int i = 0; i < n; i++){
              for(int j = i+1; j < n; j++){
                  sum = nums[i] + nums[j];
                  if(sum == target){
                      v.push_back(i);
                      v.push_back(j);
                      got = true;
                      break;
                  } 
              if(got == true)
                  break;
             }
          }
          return v;
      }
 };
    
