# Leetcode-743.-Network-Delay-Time

📡 Network Delay Time – LeetCode 743
🧠 Problem Summary
You are given a network of n nodes, labeled from 1 to n, where certain pairs of nodes are connected by directed edges with a travel time. When a signal is sent from a node k, it takes time along these edges to reach other nodes.

🔍 Your task is to determine the minimum time required for all nodes to receive the signal. If it's impossible for all nodes to receive it, return -1.

🚦 Input Format
times: List of edges in the format [u, v, w] where node u can reach node v in w time.

n: Total number of nodes.

k: The source node from which the signal is sent.

🛠️ Approach: Dijkstra's Algorithm (Min-Heap)
To solve this efficiently, we use Dijkstra’s Algorithm, as it’s perfect for finding shortest paths in a weighted graph with non-negative weights.


💡 Intuition
Build the graph using an adjacency list: For each u -> v with weight w, store this relationship.
Track distances: Use a distance[] array to store the shortest time it takes to reach each node from k.
Min-Heap (Priority Queue): Always process the node with the currently known smallest distance.
Relax edges: Update the distances to neighboring nodes if a shorter path is found.
After all nodes are processed, return the maximum distance in the distance[] array.


⚠️ Edge Cases
If any node is not reachable, it will remain at INT_MAX. In this case, return -1.

⏱️ Time and Space Complexity
Complexity	Description
⏰ Time	O(E * log V) where E is number of edges
📦 Space	O(V + E) for graph + priority queue

✅ Why Dijkstra Works Here
All edge weights are positive.
We want the shortest signal time, which maps perfectly to shortest path problems.
Dijkstra ensures each node is processed once with the shortest time.
