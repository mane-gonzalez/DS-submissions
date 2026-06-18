class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quicksort(vector<int> &nums, int left, int right) {
        if (left >= right)
            return;

        int i = left;
        int pivot = nums[right];

        for(int j = left; j < nums.size(); j++) {
            if(nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
               
            
        }

        swap(nums[i], nums[right]);

        quicksort(nums, left, i -1 );
        quicksort(nums, i + 1, right);
    }
};