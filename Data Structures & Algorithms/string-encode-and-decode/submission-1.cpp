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
            int count = 0;
            while (s[j] != '#'){
                j++;
                cout<< ++count<< endl;
            }
                

            int len = stoi(s.substr(i, j - i));
            
            result.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }

        return result;

    }
};
