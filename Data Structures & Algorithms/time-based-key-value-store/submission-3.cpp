class TimeMap {
private: 
    unordered_map<string, vector<pair<string, int>>> map;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
        
    }
    
    string get(string key, int timestamp) {
        const vector<pair<string, int>>& placeholder = map[key];

        int left = 0;
        int right = (int)placeholder.size() - 1;
        string result = "";

        while(left <= right) {
            int mid = left + (right - left)/2;

            if(placeholder[mid].second <= timestamp) {
                result = placeholder[mid].first;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result; 
    }
};
