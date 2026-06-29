class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;

        int row = 0;

        while(top <= bottom) {
            int mid = top + (bottom - top) / 2;

            if(matrix[mid][0] > target) {
                bottom = mid -1;
            } else if(matrix[mid][matrix[0].size() - 1] < target) {
                top = mid + 1;
            } else {
                row = mid;
                break;
            }
        }

        int left = 0;
        int right = matrix[row].size() - 1;

        while(left <= right) {
            int mid = left + (right - left)/2;

            if(matrix[row][mid] < target) {
                left = mid + 1;
            } else if( matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
