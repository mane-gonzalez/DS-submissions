class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left)/2;

            if(nums[left] < target) {
                left++;
            } else if (nums[right] > target) {
                right--;
            } else {
                return mid;
            }
        }

        return -1; 
        
    }
};
