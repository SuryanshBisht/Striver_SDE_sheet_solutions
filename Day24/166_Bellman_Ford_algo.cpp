// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V, 1e8);//we need max dist as 1e8 for some reason;
        dist[S] = 0;
        for(int count = 0; count < V; count++){//V relaxations
            for(auto x : adj){
                int u = x[0], v = x[1], w = x[2];
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
        return dist;
    }
};