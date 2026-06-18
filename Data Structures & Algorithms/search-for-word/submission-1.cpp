class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int index = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(helper(board, word, index, m, n, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>> &board, string word, int index, int m, int n, int i , int j){
        if(index == word.length())
            return true;

        if(i < 0 || i > m - 1 || j < 0 || j > n - 1 || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '*';

        if(helper(board, word, index + 1, m, n, i + 1, j) ||
           helper(board, word, index + 1, m, n, i, j + 1) ||
           helper(board, word, index + 1, m, n, i - 1, j) ||
           helper(board, word, index + 1, m, n, i, j - 1) ){
            return true;
           }

        board[i][j] = temp;

        return false;
    }
};
