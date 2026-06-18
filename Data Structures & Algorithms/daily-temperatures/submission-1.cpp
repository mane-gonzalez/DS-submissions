class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> result (temperatures.size());

        for(int i = 0; i < temperatures.size(); i ++) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int index = stk.top();
                stk.pop();

                result[index] = i - index;
            }

            stk.push(i)            ;
        }

        return result; 
    }
};
