// https://www.codingninjas.com/codestudio/problems/1082553?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
#include<bits/stdc++.h>
#define endl '\n'
// int parent[100001];
// int siz[1000001];
struct node{
    int u, v, w;
    node(int a, int b, int c){
        u = a;
        v = b;
        w = c;
    }
};



bool cmp(node a, node b){
    return a.w < b.w;
}

class DisjSet{
    vector<int> parent, siz;
    int n;
    public:
    DisjSet(int n){
        this -> n = n;
        parent.resize(n + 1);
        siz.resize(n + 1);
        for(int i = 0; i <= n ; i++) parent[i] = i;
    }
    
    int find(int u){
//         cout<<u<<' '<<parent[u]<<"call ended\n";
        return parent[u] = (parent[u] == u) ? u : find(parent[u]);
        //quite a LETHAL mistake to do
        //return parent[u] = (parent[u] == u) ? u : find(u);
    }

    void Union(int u, int v){
        int U = find(u), V = find(v);
        if(U == V) return ;
        if(siz[U] > siz[V]){
            siz[U] += siz[V];
            siz[U] = 0;
            parent[V] = U;
        }
        else{
            siz[V] += siz[V];
            siz[V] = 0;
            parent[U] = V;
        }
    }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    vector<node> edges;
    for(int i = 0; i < m; i++){
        edges.push_back(node(graph[i][0], graph[i][1], graph[i][2]));
    }
//     edges.push_back(node(1, 2, 8));
    sort(edges.begin(), edges.end(), cmp);
//     memset(parent, 0, sizeof(parent));
//     for(int i = 0; i <= n ; i++) parent[i] = i;
    int dist = 0;
    DisjSet mst(n + 1);
   
    for(auto it : edges) {
        int u = it.u, v = it.v, w = it.w;
//         cout<<mst.find(u)<<' '<<mst.find(v)<<' ';
        if(mst.find(v) != mst.find(u)) {
            dist += w; 
            mst.Union(u, v); 
        }
//         cout<<mst.find(u)<<' '<<mst.find(v)<<endl;
    }
//     for(int i = 0; i < m; i++){
//         int u = edges[i].u, v = edges[i].v, w = edges[i].w;
//         if(find(u) == find(v)) continue;
//         dist += w;
//         Union(u, v);
//     }
    return dist;
}