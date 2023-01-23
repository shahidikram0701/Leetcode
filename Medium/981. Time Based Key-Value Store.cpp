// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
private:
    unordered_map<string, set<int>> timestamps;
    unordered_map<string, unordered_map<int, string>> timemap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(timestamps.find(key) == timestamps.end()) {
            timestamps[key] = {};
        }
        timestamps[key].insert(timestamp);
        
        if(timemap.find(key) == timemap.end()) {
            timemap[key] = unordered_map<int, string>{};
        }
        timemap[key][timestamp] = value;
        
//         cout << key << "; " << timestamp << ": ";
//         cout << timemap[key][timestamp] << endl;
        
    }
    
    string get(string key, int timestamp) {
        if(timemap.find(key) == timemap.end()) {
            return "";
        }
        
        auto it = timestamps[key].lower_bound(timestamp);
        if(it == timestamps[key].end()) {
            it--;
        } else {
            if(*it > timestamp) {
                it--;
            }
        }
        
        int t = *it;
        
        // cout << "key: " << key << " at timestamp: " << t << endl; 
        if(t <= timestamp) {
            return timemap[key][t];
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