class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(backtrack(board, word, 0, m, n, i, j))
                        return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>> &board, string word, int index, int m, int n, int i, int j){
        if(index == word.length())
            return true;

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '*';

        if(backtrack(board, word, index + 1, m, n, i + 1, j) || 
           backtrack(board, word, index + 1, m, n, i - 1, j) ||
           backtrack(board, word, index + 1, m, n, i, j + 1) ||
           backtrack(board, word, index + 1, m, n, i, j - 1) ){
            return true;
           } 
        
        board[i][j] = temp;

        return false;
           
    }
};
