// https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void DFS(Node *root, unordered_map<Node*, bool> &vis){
        vis[root] = true;
        cout<<root -> val<<' ';
        for(auto x: root -> neighbors){
            // cout<<x -> val<<' ';
            if(!vis[x]){
                DFS(x, vis);
            }
        }
    }
    
    void BFS(Node *root, unordered_map<Node*, bool> &vis){
        queue<Node*> q;
        q.push(root);
        vis[root] = 1;
        while(q.size()){
            Node* i = q.front();
            cout<<i -> val<<"-";
            q.pop();
            for(auto x: i -> neighbors){
                cout<<x -> val<<' ';
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
            cout<<endl;
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            Node*clone = nullptr;
            return clone;
        }
        Node *clone = new Node(node -> val);
        unordered_map<Node*, bool> vis;
        unordered_map<Node*, Node*> cloneOfOrig, prev;
        queue<pair<Node*, Node*>> q;
        
        q.push({node, clone});
        vis[node] = 1;
        vis[clone] = 1;
        cloneOfOrig[node] = clone;
        prev[node] = nullptr;
        // vis.clear();
        // DFS(node, vis);cout<<endl;
        // vis.clear();
        // DFS(clone, vis);
        while(q.size()){
            Node* i = q.front().first, *cl = q.front().second;
            q.pop();
            for(auto x: i -> neighbors){
                if(!vis[x]){
                    vis[x] = 1;
                    prev[x] = i;
                    Node* temp = new Node(x -> val);
                    cloneOfOrig[x] = temp;
                    vis[temp] = 1;
                    cl -> neighbors.push_back(temp);
                    temp -> neighbors.push_back(cl);
                    q.push({x, temp});
                }
                else if(x != prev[i]){
                    cloneOfOrig[x] -> neighbors.push_back(cl);
                }
            }
        }
        
        
        
        // vis.clear();
        // BFS(node, vis);cout<<endl;
        // vis.clear();
        // BFS(clone, vis);
        
        return clone;
    }
};