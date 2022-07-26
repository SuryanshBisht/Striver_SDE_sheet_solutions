// https://practice.geeksforgeeks.org/problems/topological-sort/1
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> topo, vis(V, 0);
	    queue<int> q;
	    vector<int> inDegree(V, 0);
	    for(int i = 0 ; i < V; i++){
	        for(auto x:adj[i]){
	            inDegree[x]++;
	        }
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(!inDegree[i]) {q.push(i);}
	    }
	    
	    while(q.size()){
	        int node = q.front();
	        q.pop();
	        vis[node] = 1;
	        topo.push_back(node);
	        for(auto x:adj[node]){
	            if(--inDegree[x] == 0) q.push(x);
	        }
	    }
	    
	    return topo;
	}
};