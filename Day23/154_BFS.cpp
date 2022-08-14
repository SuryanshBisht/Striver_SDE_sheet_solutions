// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> BFS;
        vector<bool> vis(V);
        BFS.push_back(0);
        for(int i = 0; i < 1; i++){
            if(vis[i]) continue;
            queue<int> q;
            q.push(i);
            // BFS.push_back(i);
            vis[i] = 1;
            while(q.size()){
                int node = q.front();
                q.pop();
                for(auto x: adj[node]){
                    if(!vis[x]){
                        vis[x] = 1;
                        BFS.push_back(x);
                        q.push(x);
                    }
                }
            }
        }
        
        return BFS;
    }
};
