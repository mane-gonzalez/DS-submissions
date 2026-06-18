class MinStack {
    private:
    stack<int> s1;
    stack<int> minStk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);

        if(minStk.empty()) {
            minStk.push(val);
        } else {
            minStk.push(min(val, minStk.top()));
        }
        
    }
    
    void pop() {
        s1.pop();
        minStk.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
