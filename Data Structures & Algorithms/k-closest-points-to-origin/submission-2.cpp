class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> result;

        for(auto point: points){
            int dist = point[0]*point[0] + point[1]*point[1];

            if(pq.size() < k){
                pq.push({dist, point});
            } else if(dist < pq.top().first){
                pq.pop();
                pq.push({dist, point});
            }
        }

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
