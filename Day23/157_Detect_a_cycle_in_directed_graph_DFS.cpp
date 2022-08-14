// https://leetcode.com/problems/course-schedule/submissions/
class Solution {
    vector<int> adj[2001];
    bool vis[2001], dfsvis[2001];
public:
    bool cycle(int node){
        // cout<<node<<' ';
        for(auto x:adj[node]){
            if(!vis[x]){
                vis[x] = 1;
                dfsvis[x] = 1;
                if(cycle(x)) return true;
                dfsvis[x] = 0;
            }
            if(dfsvis[x]) return true;
        }
        // dfsvis[node] = false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& req) {
        memset(vis, 0, sizeof(vis));
        memset(dfsvis, 0, sizeof(dfsvis));
        for(auto x:req){
            adj[x[1]].push_back(x[0]);
        }
        
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vis[i] = 1;
                dfsvis[i] = 1;
                if(cycle(i)){
                    return false;
                }
                dfsvis[i] = false;
            }
        }
        // cout<<endl;
        
        return true;
    }
};