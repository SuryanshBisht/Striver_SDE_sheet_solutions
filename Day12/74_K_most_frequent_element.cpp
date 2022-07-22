// https://leetcode.com/problems/top-k-frequent-elements/submissions/
typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> minH;
        unordered_map<int,int> freq,done;
        
        for(auto x:nums){
            freq[x]++;
        }
        
        for(auto x:nums){
            if(!done[x]){
                done[x] = 1;
                minH.push({freq[x], x});
                if(minH.size() > k) minH.pop();
            }
        }
        
        vector<int> v;
        while(minH.size()) {
            v.push_back(minH.top().second);
            minH.pop();
        }
        
        return v;
    }
};