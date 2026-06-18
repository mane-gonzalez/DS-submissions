class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left <= right) {
            int diff = target - numbers[right];

            if(diff > numbers[left]) {
                left++;
            } else if (diff < numbers[left]) {
                right--;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {};

    }
};
