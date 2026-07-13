class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = 0;

        for(int i = 0; i < piles.size(); i++) {
            maxSpeed = max(piles[i], maxSpeed);
        }

        while(minSpeed <= maxSpeed) {
            int mid = minSpeed + (maxSpeed - minSpeed)/2;

            if(canIeat(piles, mid, h)) {
                maxSpeed = mid - 1;
            } else {
                minSpeed = mid + 1;
            }
        }

        return minSpeed;
    }

    bool canIeat(vector<int> &piles, int speed, int h) {
        long long totalHours = 0;

        for(int i = 0; i < piles.size(); i++) {
            int hoursToEat = ceil(piles[i] / (double)speed);
            totalHours += hoursToEat;
        }

        return totalHours <= h;
    }
};
