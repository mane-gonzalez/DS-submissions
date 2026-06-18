class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        stack<float> stk;

        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});            
        }

        sort(cars.begin(), cars.end());

        for(int i = cars.size()-1; i >= 0 ; i--) {
            int pos = cars[i].first;
            int vel = cars[i].second;

            float time = float(target - pos)/vel;

            if(stk.empty() || time > stk.top()){
                stk.push(time);
            }
        }

        return stk.size();
        
    }
};
