class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> v;
			for(char i : s) {
				if(v.empty() || v.back().first != i) 
					v.push_back({i,1});
				else if(++v.back().second == k) 
					v.pop_back();
			}
			string ans = "";
			for(auto i : v) {
				ans.append(i.second,i.first);
			}
			return ans;
    }
};