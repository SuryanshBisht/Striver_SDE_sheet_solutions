// https://leetcode.com/problems/merge-intervals/submissions/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > v;
        v.push_back(intervals[0]);
        for(int i = 1; i < n ;i++){
            if(intervals[i][0] <= v.back()[1]){
                v.back()[1] = max(v.back()[1], intervals[i][1]);
                v.back()[0] = min(v.back()[0], intervals[i][0]);
            }
            else{
                v.push_back(intervals[i]);
            }
        }
        
        return v;
    }
};