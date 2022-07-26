// https://leetcode.com/problems/min-stack/submissions/
typedef long long int ll; // imp line
class MinStack {
    stack<ll> st;
    ll mne;
public:
    MinStack() {
        while(st.size()) st.pop();
        mne = ll(INT_MAX);
    }
    
    void push(int x) {
        ll val = x;
        if(st.size() == 0) {
            mne = val;
            st.push((val));
            return;
        }
        if(val < mne){
            st.push(2 * val - mne);
            mne = val;
            return;
        }
        st.push(val);
    }
    
     void pop(){
        if(st.size() == 0) return;
        if(st.top() >= mne){
            st.pop();
            return;
        }
        mne = 2 * mne - st.top();
        st.pop();
    }
    
    int top() {
        if(st.size() == 0) return -1;
        if(st.top() >= mne) return st.top();
        // int ans = 2 * mne - st.top();
        // return ans;
        return mne; // remember ki mne daalte time tumne hi bigada tha use
    }
    
    int getMin() {
        return mne;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */