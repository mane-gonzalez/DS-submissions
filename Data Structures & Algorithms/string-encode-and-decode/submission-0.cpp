class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for(auto s:strs) {
            result += to_string(s.size()) + '#' + s;            
        }

        return result;

    }

    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j - i));
            cout<< len << endl;
            result.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }

        return result;

    }
};
