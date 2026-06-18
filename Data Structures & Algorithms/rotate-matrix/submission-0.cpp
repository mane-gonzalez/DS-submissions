class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < (n + 1)/2; i++) {
            for(int j = 0; j < n/2; j++) {
                // Store top-left
                int temp = matrix[i][j];

                // bottom-left to top-left
                matrix[i][j] = matrix[n-j-1][i];

                // bottom-right to bottom-left
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];

                // top-right to bottom-right
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];

                // temp (original top-left) to top-right
                matrix[j][n-i-1] = temp;
            }
        }
    }
};