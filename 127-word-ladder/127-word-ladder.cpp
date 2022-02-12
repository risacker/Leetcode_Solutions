class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();
    vector<bool> checked (n, false);
    queue<string> mq;
    mq.push(beginWord);
    int level = 1;
    while(!mq.empty())
        {
            level++;
            int size = mq.size();
            for(int i = 0; i < size; i++)
                {
                    string current = mq.front();
                    mq.pop();
                    for(int j = 0; j < n; j++)
                        {
                            if(checked[j])  continue;
                            if(distance(current, wordList[j]) == 1)
                                {
                                    if(distance(wordList[j], endWord) == 0)     
                                        return level;
                                    checked[j] = true;
                                    mq.push(wordList[j]);
                                }
                        }
                }
        }
    return 0;
    }
    
private:
    int distance(string& s1, string& s2)
    {
        int dif = 0;
        for(int i = 0; i<s1.size(); i++)
            {
                if(s1[i] != s2[i]) 
                    dif++;
                if(dif > 1) 
                    return 2;
            }
    return dif;  
    }
};