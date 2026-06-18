class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string current;
        int index = 0;

        if(digits.size() < 1)
            return {};

        unordered_map<char, string> map;

        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";

        backtrack(digits, map, index, current, result);
        return result;    
    }

    void backtrack(string &digits, unordered_map<char, string> &map, int index, string &current, vector<string> &result){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }

        for(char str:map.at(digits[index])){
            current.push_back(str);
            backtrack(digits, map, index + 1, current, result);
            current.pop_back();
        }
    }
};
