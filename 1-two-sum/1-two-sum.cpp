class Solution {
 public:
      vector<int> twoSum(vector<int>& nums, int target) {
      int sum=0;
      bool got=false;
      vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
             for(int j = i+1; j < nums.size(); j++)
             {
                 sum=nums[i]+nums[j];
                     if(sum == target){
                       ans.push_back(i);
                       ans.push_back(j);
                       got = true;
                       break;
              }
          if(got == true)
              break;
         }
        }
        return ans;
      }
 };
    