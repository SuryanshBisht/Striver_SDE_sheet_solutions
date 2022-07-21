// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
class Solution{
    int node_color[101];
public:
    bool colorNode(bool graph[][101], int node, int m, int n){
        if(node == n) return true;
        unordered_map<int,int> used;
        for(int i = 0 ; i < 101; i ++){
            if(graph[node][i]){
                if(node_color[i]) used[node_color[i]] = 1;
            }
        }
        
        for(int i = 1; i <= m; i++){
            if(!used[i]){
                node_color[node] = i;
                if(colorNode(graph, node + 1, m, n)) return true;
                node_color[node] = 0;
            }
        }
        return false;
        // if(node_color[node] == 0) return false;
        // bool res = true;
        // for(int i = 0; i < 101; i ++){
        //     if(graph[node][i]){
        //         if(!node_color[i]){
        //             res &= colorNode(graph, i, m);
        //         }
        //     }
        // }
        
        // return colorNode(graph, node + 1, m, n);
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        memset(node_color, 0, sizeof(node_color));
        return colorNode(graph, 0, m, n);
    }
};
