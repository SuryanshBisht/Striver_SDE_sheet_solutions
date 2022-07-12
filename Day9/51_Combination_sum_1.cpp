// https://leetcode.com/problems/combination-sum/submissions/
vector<vector<int>> res;
vector<int> v;
void combSum(vector<int> &candidates,int sum, int target, int ind){
    if(sum == target){
        res.push_back(v);
        return;
    }
    if(ind == candidates.size() || sum > target) {
        return;
    }
    
    for(int i = ind; i < candidates.size(); i++){
        v.push_back(candidates[i]);
        combSum(candidates, sum + candidates[i], target, i);
        v.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        v.clear();
        combSum(candidates,0, target, 0);
        return res;
    }
};