class TimeMap {
private:
unordered_map<string, pair<vector<string>, vector<int>>> storage; // name to arrays
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        storage[key].first.push_back(value);
        storage[key].second.push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        vector<int> arr = storage[key].second;
        int l = 0, u = arr.size() - 1;
        int index;
        bool f = false;
        while(l <= u)
        {
            int m = l + (u - l) / 2;
            if(arr[m] == timestamp)
            {
                index = m;
                f = true;
                break;
            } else if (arr[m] < timestamp) 
            {
                f = true;
                index = m;
                l = m + 1;
            }
            else u = m - 1;
        }
        if (!f) return "";
        else return storage[key].first[index];
    }
};
