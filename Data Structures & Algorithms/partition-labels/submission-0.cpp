class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> store(26);
        vector<int> result;

        int size = 0;
        int end = 0;

        for(int i = 0; i < n ; i++) {
            store[s[i] - 'a'] = i;
        }

        for(int i = 0; i < n; i++) {
            end = max(end, store[s[i] - 'a']);

            size++;

            if(i == end){
                result.push_back(size);
                size = 0;
            }
        }

        return result;
    }
};
