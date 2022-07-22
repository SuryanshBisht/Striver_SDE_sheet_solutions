// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> minH;
        unordered_map<int,int> freq;
        int repeats = 0;
        
        for(auto x:nums){
            minH.push(x);
            if(minH.size() > k){
                minH.pop();
            }
        }
        
        return minH.top();
    }
};