class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_size = board.size();
        int col_size = board[0].size();

        const int size = 9;
        bool row[size][size] = {false};
        bool col[size][size] = {false};
        bool grid[size][size] = {false};

        for(int i = 0; i < row_size; i++) {
            for(int j = 0; j < col_size; j++) {

                if(board[i][j] == '.')
                    continue;

                int index = board[i][j] - '0' - 1;
                int cuadrant = (i/3)*3 + j/3;

                if(row[i][index] || col[j][index] || grid[cuadrant][index])
                    return false;

                row[i][index] = true;
                col[j][index] = true;
                grid[cuadrant][index] = true;
            }
        }

        return true;
    }
};
