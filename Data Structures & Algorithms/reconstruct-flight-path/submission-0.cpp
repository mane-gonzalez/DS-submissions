class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;

        vector<string> result;

        for(const auto &ticket: tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK", graph, result);

        reverse(result.begin(), result.end());

        return result;
    }

private:
    void dfs( const string &airport, unordered_map<string, multiset<string>> &graph, vector<string> &result ) {
        while(!graph[airport].empty()) {
            auto next = *graph[airport].begin();

            graph[airport].erase(graph[airport].begin());

            dfs(next, graph, result);
        }

        result.push_back(airport);
    }

};