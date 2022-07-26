// https://www.codingninjas.com/codestudio/problems/920551?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
#include<bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size(), m = edges[0].size();
    vector<int> color(n, -1);
    vector<int> adj[n];
    for(int i = 0; i < n;  i++){
        for(int j = 0; j < m; j++){
            if(edges[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            queue <pair<int,int>> q;
            q.push({i, -1});
            while(q.size()){
                int node = q.front().first, prev = q.front().second;
                if(prev == -1){color[node] = 0;}
                else color[node] = 1 - color[prev];
                q.pop();
                for(auto x: adj[node]){//it was node , shit
                    if(color[x] != -1){
                        if(x == prev) continue;
                        else {
//                            cout<<color[x]<<' '<<color[prev]<<x<<' '<<prev<<endl;
                           ans &= (color[x] != color[node]);
                           break;
                        }
                    }
                    else q.push({x, node});
                }
            }
        }
    }
    
    return ans;
}