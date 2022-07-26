// https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    vector<int> adj[n + 1];
    for(int i = 0 ; i < m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            stack<pair<int,int>> st;
            st.push(make_pair(i, -1));
            while(st.size()){
                int node = st.top().first, prev = st.top().second;
                st.pop();
                vis[node] = 1 
                for(auto x:adj[node]){
                    if(vis[x]){
                        if(x == prev) continue;
                        return "Yes";
                    }
                    else st.push({x, node});
                }
            }
        }
    }
    return "No";
}

