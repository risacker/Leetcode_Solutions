class Solution {
 public:
      vector<int> twoSum(vector<int>& nums, int target) {
         /* (brute force soln)
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
          */
          
          //(hashing soln)
          
          vector<int> ans;
          unordered_map<int, int> m;
          for(int i = 0; i < nums.size(); ++i){
              if(m.find(target - nums[i]) != m.end()){
                  ans.emplace_back(i);
   		          ans.emplace_back(m[target - nums[i]]);
   		          return ans;
   	          }
              m[nums[i]] = i;
           }
          return ans;
      }
 };
    
