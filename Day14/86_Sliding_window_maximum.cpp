// https://leetcode.com/problems/sliding-window-maximum/submissions/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        //better ans using deque, kinda mix of maxStack in O(n);
        deque<int> dq;// note that it will store indices!
        vector<int> ans;
        for(int i = 0; i < v.size() ; i++){
            if(dq.front() == i - k) dq.pop_front(); // this will compulsarily deleted regardless of its value
            while(dq.size() && v[dq.back()] <= v[i]) dq.pop_back(); // we want all less values deleted
            // so it becomes a "decreasing" array with max at front
            dq.push_back(i);
            if(i >= k - 1)  ans.push_back(v[dq.front()]);
        }
        
        return ans;
    }
};

// multiset ans, does gets accepted, but badly at O(nlogK);
//     multiset<int> s;
//     vector<int> ans;
//     for(int i = 0; i < k; i++){
//         s.insert(v[i]);
//     }

//     ans.push_back(*(s.rbegin()));
//     for(int i = k; i < v.size(); i++){
//         s.erase(s.find(v[i - k]));
//         s.insert(v[i]);
//         ans.push_back(*(s.rbegin()));
//     }

//     return ans;