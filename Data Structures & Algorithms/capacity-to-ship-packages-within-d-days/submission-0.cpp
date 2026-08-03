class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0;
        int totalWeight = 0;
        

        for(int i = 0; i < weights.size(); i++) {
            maxWeight = max(weights[i], maxWeight);
            totalWeight += weights[i];
        }

        int res = totalWeight;

        while(maxWeight <= totalWeight) {
            int cap = maxWeight + (totalWeight - maxWeight)/2;

            if(canIship(weights, days, cap)) {
                res = min(res, cap);
                totalWeight = cap - 1;
            } else {
                maxWeight = cap + 1;
            }
        }

        return res;
    }

    bool canIship(vector<int> & weights, int days, int cap) {
        int ships = 1;
        int currCap = cap;

        for (int w : weights) {
            if (currCap - w < 0) {
                ships++;
                if (ships > days) {
                    return false;
                }
                currCap = cap;
            }
            currCap -= w;
        }
        return true;
    }
};