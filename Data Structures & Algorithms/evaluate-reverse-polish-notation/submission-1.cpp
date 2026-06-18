class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;

        for(auto str:tokens) {
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                int b = result.top();
                result.pop();

                int a = result.top();
                result.pop();

                if(str == "+") {
                    result.push(a+b);
                } else if (str == "-") {
                    result.push(a-b);
                } else if (str == "/" ) {
                    result.push(a/b);
                } else if (str == "*") {
                    result.push(a*b);
                }
            } else {
                result.push(stoi(str));
            }
        }

        return result.top();
        
    }
};
