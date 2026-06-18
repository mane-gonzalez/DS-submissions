class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        
        for(auto asteroid:asteroids) {
            bool stillExploding = true;

            while(stillExploding && asteroid < 0 && !stk.empty() && stk.top() > 0 ) {
                if(stk.top() < abs(asteroid)) {
                    //kill left
                    stk.pop();
                } else if(stk.top() == abs(asteroid)) {
                    stk.pop();
                    stillExploding = false;
                } else {
                    stillExploding = false;
                }
            }

            if(stillExploding) 
                stk.push(asteroid);
            
        }
        
        vector<int> result(stk.size());
        for(int i = result.size() - 1; i >=0 ; i--) {
            result[i] = stk.top();
            stk.pop();
        }

        return result; 

    }
};