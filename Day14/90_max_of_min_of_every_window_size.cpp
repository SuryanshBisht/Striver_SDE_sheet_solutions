// https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> v, int n) {
    vector<int> ans(n, -1e9), prevSmaller(n), nextSmaller(n);
    stack<int> st;
    st.push(-1);
    for(int i = 0; i < n; i++){
        while(st.size() > 1 && v[st.top()] >= v[i]){
            st.pop();
        }
        prevSmaller[i] = st.top();
        st.push(i);
    }
    
    while(st.size()) st.pop();
    st.push(n);
    
    for(int i = n - 1; i >= 0; i--){
        while(st.size() > 1 && v[st.top()] >= v[i]){
            st.pop();
        }
        nextSmaller[i] = st.top();
        st.push(i);
    }
    
    for(int i = 0; i < n; i++){
        int l = prevSmaller[i], r = nextSmaller[i];
        ans[r - l  - 2] = max(ans[r - l - 2], v[i]);
    }
    
    for(int i = n - 2; i >= 0; i--){
        ans[i] = max(ans[i], ans[i + 1]);
    }
//     ans[0] = *max_element(v.begin(), v.end());
    
    return ans;
}