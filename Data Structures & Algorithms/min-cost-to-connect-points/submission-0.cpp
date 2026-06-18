class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);

        minDist[0] = 0;
        int result = 0;

        for(int i = 0; i < n; i++) {
            int minDistance = INT_MAX;
            int currentPoint = -1;

            for(int j = 0; j < n; j++) {
                if(!visited[j] && minDist[j] < minDistance) {
                    minDistance = minDist[j];
                    currentPoint = j;
                }                
            }

            visited[currentPoint] = true;
            result += minDistance;

            for(int j = 0; j < n; j++) {
                int manhattan = abs(points[currentPoint][0] - points[j][0]) + abs(points[currentPoint][1] - points[j][1]);
                minDist[j] = min(minDist[j], manhattan);
            }

        }
        return result;        
    }
};
