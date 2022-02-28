class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)
            return ans;
        string s;
        s+=to_string(nums[0]);
        if(nums.size()==1)
        {
            ans.push_back(s);
            return ans;
        }
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]+1){
                cnt++;
                if(i==nums.size()-1)
                {
                    s+="->";
                    s+=to_string(nums[i]);
                    ans.push_back(s);
                    return ans;
                }
                continue;
            }
            if(cnt){
            s+="->";
            s+=to_string(nums[i-1]);
            }
            cnt=0;
            ans.push_back(s);
            s.clear();
            s+=to_string(nums[i]);
            if(i==nums.size()-1)
            {
                ans.push_back(s);
            }
        }
        return ans; 
    }
};