class Solution {
public:
    bool isValid(string s) {
        stack<char> openStack;

        unordered_map<char, char> closeToOpen;

        closeToOpen[')'] = '(';
        closeToOpen[']'] = '[';
        closeToOpen['}'] = '{';

        for(auto c: s ) {
            if(closeToOpen.find(c) != closeToOpen.end()) {
            if(!openStack.empty() && openStack.top() == closeToOpen[c]) {
                openStack.pop();
            } else {
                return false;
            }
        } else {
            openStack.push(c);
        }
        }
        

        return openStack.empty(); 


    }
};
