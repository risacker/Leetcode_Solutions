class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jS = jewels.size();
        int sS = stones.size();
        int cnt = 0;
        for(int i = 0; i < sS; i++)
            for( int j = 0; j < jS; j++)
                if(stones[i] == jewels[j])
                    cnt++;
        return cnt;
    }
};
