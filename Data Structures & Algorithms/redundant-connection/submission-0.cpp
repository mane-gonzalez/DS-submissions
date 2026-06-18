class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1, - 1);

        for(auto edge:edges){
            int x = find(edge[0], parent);
            int y = find(edge[1], parent);

            if(x == y){
                return {edge[0], edge[1]};                
            } else {
                parent[x] = y;
            }
        }

        return {};
    }

    int find(int n, vector<int> &parent){
        if(parent[n] == -1) {
            return n;
        } else {
            return find(parent[n], parent);
        }
        
    }
};
