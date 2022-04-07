class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size()-1;
        while(n > 0){
            if(stones[n] == stones[n - 1]){
                if(stones.size() == 2)
                    return 0;
                stones.pop_back();
                stones.pop_back();
                n -= 2;
            }
            else{
                stones[n - 1] = abs(stones[n] - stones[n-1]);
                stones.pop_back();
                sort(stones.begin(), stones.end());
                n--;
            }
        }
        return stones[0];
    }
};