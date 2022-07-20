// https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v, vector<int>& u) {
        stack<int> stk;
        stk.push(-1);
        unordered_map<int,int> nextGreater;
        int n = v.size(), m = u.size();
        for(int i = m - 1; i >= 0 ; i--){
            while(stk.top() != -1 && u[i] >= stk.top()){
                stk.pop();
            }
            nextGreater[u[i]] = stk.top();
            // cout<<nextGreater[u[i]]<<' ';
            stk.push(u[i]);
        }
        
        for(int i = 0;  i < n; i++){
            v[i] = nextGreater[v[i]];
        }
        
        return v;
    }
};