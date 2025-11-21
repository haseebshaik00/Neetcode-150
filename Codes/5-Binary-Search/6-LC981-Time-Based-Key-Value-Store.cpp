class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {}
    
    // Time: O(1) | Space: O(1)
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    // Time: O(log n) | Space: O(1)
    string get(string key, int timestamp) {
        auto &x = store[key];
        int i=0, j = x.size()-1, ans=-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(x[mid].first <= timestamp){
                ans = mid;
                i=mid+1;
            }
            else j=mid-1;
        }
        return (ans!=-1 && ans < x.size()) ? x[ans].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */