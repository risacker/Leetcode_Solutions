class TimeMap {
unordered_map<string, map<int, string> > records;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        records[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(records.count(key)) {
            auto it = records[key].lower_bound(timestamp);
            return it != records[key].end() && it->first == timestamp ? it->second  : (it == records[key].begin() ? "" : (--it)->second);
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */