// Problem: Network Delay Time
// Platform: Leetcode (Problem 743)
// Approach: Dijkstra's Algorithm using Min-Heap
// Author: [Your Name or GitHub handle] 🚀

class Solution {
public:

    // Helper function to run Dijkstra's algorithm
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Adjacency list where each node maps to (neighbor, weight)
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            mp[u].push_back({v, wt});
        }

        // Min-heap to get the next node with the smallest distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        vector<int> ans(V + 1, INT_MAX); // 1-based indexing
        ans[src] = 0; // Distance to source is 0
        q.push({0, src}); // (distance, node)

        while (!q.empty()) {
            auto [cost, node] = q.top();
            q.pop();

            for (auto [neigh, weight] : mp[node]) {
                if (ans[neigh] > cost + weight) {
                    ans[neigh] = cost + weight;
                    q.push({ans[neigh], neigh});
                }
            }
        }

        return ans;
    }

    // Main function to compute the time it takes for all nodes to receive signal
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> ans = dijkstra(n, times, k);
        int maxans = 0;

        // Check if all nodes are reachable
        for (int i = 1; i <= n; i++) {
            if (ans[i] == INT_MAX)
                return -1; // Node not reachable
            maxans = max(maxans, ans[i]);
        }

        return maxans;
    }
};
