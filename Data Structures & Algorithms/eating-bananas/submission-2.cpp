class Solution {
    public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = 0;

        for(int i = 0 ; i < piles.size(); i++) {
            maxSpeed = max(maxSpeed, piles[i]);
        }
        

        while(minSpeed <= maxSpeed) {
            int mid = (minSpeed + maxSpeed)/2;

            if(canIeat(piles, h, mid)){
                maxSpeed = mid -1;
            } else {
                minSpeed = mid + 1;
            }

        }
        return minSpeed;
    }

private: 
    bool canIeat(vector<int> &piles, int h, int speed) {
      long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int hoursToEatPile = ceil(piles[i] / (double)speed);
            totalHours += hoursToEatPile;
        }
        return totalHours <= h;

    }
};
