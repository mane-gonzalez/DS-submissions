class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeToOpen;
        stack<char> stk;

        closeToOpen[')'] = '(';
        closeToOpen[']'] = '[';
        closeToOpen['}'] = '{';

        for(auto c:s) {
            if(closeToOpen.find(c) != closeToOpen.end()){
                if(!stk.empty() && stk.top() == closeToOpen[c]) {
                    stk.pop();
                } else {
                    return false; 
                }
            } else {
                stk.push(c);
            }
        } 
        return stk.empty();
    }
};
