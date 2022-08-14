// https://leetcode.com/problems/critical-connections-in-a-network/
#include<bits/stdc++.h>
class Solution {
    int time[100001], low[100001];
    vector<vector<int>> ans;
    vector<int> adj[100001];
    int vis[100001];
public:
    void DFS(int node, int parent, int t){
        time[node] = t++;
        low[node] = time[node];
        int child = 0;
        for(auto x : adj[node]){
            if(vis[x]) continue;
            vis[x] = 1;
            DFS(x, node, t);
            if(low[x] > time[node]) ans.push_back({x, node});
        }
        
        for(auto x : adj[node]){
            if(x == parent) continue;
            low[node] = min(low[node], low[x]);
        }
        
        return;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        ans.clear();
        memset(vis, 0, sizeof(vis));
        // memset(low, -1, sizeof(low));
        int t = 0;
        time[0] = 1;
        low[0] = 1;
        vis[0] = 1;
        DFS(0, -1, t);
        return ans;
    }
};