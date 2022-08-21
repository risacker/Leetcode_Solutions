string pattern;
string str;
bool compare(int pos)
{
    bool ret = true;
    int same = 0;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (str[i + pos] == '?')
        {
            same++;
            continue;
        }
        else if (str[i + pos] != pattern[i])
            return false;
    }
    if (same != pattern.length())
        return true;
    return false;
}

class Solution
{
  public:
    vector<int> movesToStamp(string stamp, string target)
    {
        pattern = stamp;
        str = target;

        int limit = 10 * target.size();
        deque<int> ret;
        int done = target.size();
        int prv = -1;

        while (prv != ret.size() && ret.size() < limit)
        {
            prv = ret.size();

            for (int i = 0; i <= str.size() - pattern.size(); i++)
            {
                if (compare(i))
                {
                    ret.push_front(i);
                    for (int x = 0; x < pattern.size(); x++)
                    {
                        done -= str[i + x] != '?';
                        str[i + x] = '?';
                    }
                }
            }
        }
        if (done == 0)
            return vector<int>{ret.begin(), ret.end()};
        return vector<int>();
    }
};