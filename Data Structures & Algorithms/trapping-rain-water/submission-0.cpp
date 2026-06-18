class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;

        int leftHeight = height[left];
        int rightHeight = height[right];

        int result=0;

        while(left < right) {
            if(rightHeight > leftHeight) {
                left++;
                leftHeight = max(leftHeight, height[left]);
                result += leftHeight - height[left];
            } else {
                right--;
                rightHeight = max(rightHeight, height[right]);
                result += rightHeight - height[right];
            }
        }
        return result; 
    }
};
