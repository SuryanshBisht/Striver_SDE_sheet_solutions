// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
typedef pair<int,int> pii;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pii, vector<pii> , greater<pii>> minH;
        // minH.push({S, 0}); for god's sake
        minH.push({0, S});
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        // memset(dist, -1, sizeof(dist));
        while(minH.size()){
            int dis = minH.top().first;
            int node = minH.top().second;
            minH.pop();
            for(auto x: adj[node]){
                if(dist[x[0]] > dis + x[1]){
                    dist[x[0]] = dis + x[1];
                    minH.push({dis + x[1], x[0]});
                }
            }
        }
        return dist;
    }
};