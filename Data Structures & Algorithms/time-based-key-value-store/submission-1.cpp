class TimeMap {
public:

    unordered_map<string, vector<pair<string, int>>> keyStore;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {

        const vector<pair<string, int>> &placeholder = keyStore[key];

        int left = 0;
        int right = placeholder.size() - 1;

        string result = "";

        while (left <= right) {
            int mid = (left + right);
            
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
