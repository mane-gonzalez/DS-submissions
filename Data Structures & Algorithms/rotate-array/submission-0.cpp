class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int simplyK = k % n;

        reverse(nums, 0 ,n - 1);
        reverse(nums, 0, simplyK - 1);
        reverse(nums, simplyK, n - 1);
        
    }

    void reverse(vector<int>& nums, int left, int right) {
        while(left < right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

    }
};