class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool increasing = true;
        if(arr.size() == 1)
            return 0;
        if(arr[0] > arr[1] || arr[0] == arr[1])
            return 0;
        for (int i = 1; i < arr.size() - 1;i++){
            if(arr[i] == arr[i+1]){
                return 0;
            }
            if(!increasing) {
                if(arr[i] < arr[i+1])
                    return 0;
            }
            if(arr[i] > arr[i+1])
                increasing = false;
        }
        if(increasing){
            return 0;
        }
        return 1;
    }
};