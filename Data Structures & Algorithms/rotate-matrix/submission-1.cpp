class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < (n+1)/2; i++) {
            for(int j = 0; j < n/2; j++) {
                //tl
                int temp = matrix[i][j];

                //bl to tl
                matrix[i][j] = matrix[n-j-1][i];

                //br to bl
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];

                //tr to br
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];

                //tl to tr
                matrix[j][n-i-1] = temp;

            }

            
        }
    }
};