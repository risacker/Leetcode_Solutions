class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
         vector<string> v;
         int minm = INT_MAX;
         for(int i = 0; i < list1.size(); i++){
                for(int j = 0; j < list2.size(); j++){
                    if(list1[i] == list2[j]){
                        if (i + j < minm){
                            minm = i + j;
                            v.clear();
                            v.push_back(list1[i]);
                        }
                        else if(i + j == minm)
                            v.push_back(list1[i]);
                    }
                }
            }
            return v;
    }
};