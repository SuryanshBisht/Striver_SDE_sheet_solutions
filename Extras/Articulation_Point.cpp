// https://practice.geeksforgeeks.org/problems/articulation-point-1/0

class Solution {
    bool art[10001];
    int tin[10001], low[10001];
    
    void DFS(int node, int parent, int &t, vector<int> adj[]){
        low[node] = tin[node];
        t++;
        int child = 0;
        
        for(auto x : adj[node]){
            if(tin[x]) continue;
            tin[x] = t;
            DFS(x, node, t, adj);
            if(low[x] >= tin[node] && parent != -1) art[node] = 1;
            child++;
        }
        
        if(child > 1 && parent == -1) art[node] = 1;
        
        for(auto x : adj[node]){
            if(x == parent) continue;
            low[node] = min(low[node], low[x]);
        }
        
    }
    
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> ans;
        memset(art,0,sizeof(art));
        memset(tin, 0, sizeof(tin));
        tin[0] = 1;
        int t = 1;
        DFS(0, -1, t, adj);
        for(int i = 0; i < V; i++){
            if(art[i]) ans.push_back(i);
        }
        
        if(ans.empty()) ans.push_back(-1);
        return ans;
    }

};