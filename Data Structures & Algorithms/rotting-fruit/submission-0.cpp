class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int minutes = 0;
        vector<vector<int>> dirs = {{0,1} , {0, -1}, {1, 0}, {-1, 0}};

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            bool hasNewRotten = false;

            for(int i = 0; i < size; i++){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for(int j = 0; j < dirs.size(); j++){
                    int x = row + dirs[j][0];
                    int y = col + dirs[j][1];

                    if(x < 0 || x>= rows || y < 0 || y >= cols){
                        continue;
                    }

                    if(grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                        hasNewRotten = true;
                    }
                }              
            }
             if(hasNewRotten)
                    minutes++;    
        }
            return (fresh == 0) ? minutes: -1;

    }
};