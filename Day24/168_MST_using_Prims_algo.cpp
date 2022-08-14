// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

typedef pair<int,int> pii;
class Solution
{
    int mst[100001];
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        memset(mst, 0, sizeof(mst));
        int dist = 0;
        priority_queue<pii, vector<pii>, greater<pii>> minH;
        minH.push({0,0});
        while(minH.size()){
            int d = minH.top().first, u = minH.top().second;
            minH.pop();
            if(mst[u]) continue;
            dist += d;
            mst[u] = 1;
            for(auto x : adj[u]){
                int v = x[0], w = x[1];
                if(mst[v]) continue;
                minH.push({w, v});
            }
        }
        return dist;
    }
};