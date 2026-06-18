#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create the adjacency list for the graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].emplace_back(v, w);
        }

        // Min-heap priority queue to store {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // Distance vector to store the shortest time to each node, initialize with infinity
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Start from node k with time 0
        minHeap.push({0, k});

        while (!minHeap.empty()) {
            auto [currentDist, u] = minHeap.top();
            minHeap.pop();

            // Skip if the current distance is greater than the recorded distance (outdated entry)
            if (currentDist > dist[u]) continue;

            // Process each neighbor of the current node
            for (const auto& [v, w] : graph[u]) {
                int newDist = currentDist + w;
                // If a shorter path is found to neighbor v, update it
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    minHeap.push({newDist, v});
                }
            }
        }

        // Find the maximum time from the distance vector, ignoring index 0 since nodes are 1-indexed
        int maxTime = *max_element(dist.begin() + 1, dist.end());
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};