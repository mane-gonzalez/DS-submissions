class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        stack<float> stk;

        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());

        for(int i = position.size() - 1; i >= 0; i--) {
            int pos = cars[i].first;
            int speed = cars[i].second;

            float time = (float)(target - pos)/speed;

            if(stk.empty() || time > (float)stk.top())
                stk.push(time);
        }

        return stk.size();
    }
};
