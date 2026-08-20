class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = 0;
        long long right = 0;

        for(int num: nums) {
            
            left = max(left, (long long)num );
            right += num;
        }
        

        while(left < right) {
            long long mid = left + (right - left)/2;

            if(canSplit(nums, k, mid)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return (int)left;
    }

    bool canSplit(vector<int> &nums, int k, long long maxSum) {
        int pieces = 1;
        long long currentSum = 0;

        for(int num:nums) {
            if(currentSum + num > maxSum) {
                pieces++;
                currentSum = num;
                if(pieces > k) 
                    return false;
            } else {
                currentSum += num;
            }

        }
        return true;
    }
};