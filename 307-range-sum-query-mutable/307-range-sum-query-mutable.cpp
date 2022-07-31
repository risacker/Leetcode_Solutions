class NumArray {
public:
    vector<int>v;
    int sum = 0;
    NumArray(vector<int>& nums) {
    v = nums;
    for(auto x:v)
        sum+=x;
    }
    
    void update(int index, int val) {
        sum -= v[index];
        v[index] = val;
        sum += val;
    }
    int sumRange(int left, int right) {
        int s = 0;
        for(int i = 0;i < left;++i)
            s += v[i];
        for(int i = right+1;i < v.size();++i)
            s += v[i];
        return sum-s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */