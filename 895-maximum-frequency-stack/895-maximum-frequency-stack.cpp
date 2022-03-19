class FreqStack {
public:
    int maxFreq;
    unordered_map<int, int> freqMap;  
    unordered_map<int, stack<int>> groupFreqMap;      
    FreqStack() {
        maxFreq = 0;
    }
    void push(int val) {
        freqMap[val]++;
        int freq = freqMap[val];
        maxFreq = max(maxFreq, freq);
        groupFreqMap[freq].push(val);
    }   
    int pop() {
        int ele = groupFreqMap[maxFreq].top();
        groupFreqMap[maxFreq].pop();
        freqMap[ele]--;
        if(groupFreqMap[maxFreq].empty()) {
            maxFreq--;
        }
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */