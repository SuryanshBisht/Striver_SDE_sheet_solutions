// https://leetcode.com/problems/combination-sum-ii/solution/
vector<vector<int>> ans;
vector<int> v;

void combSum(vector<int> &candidates, int target, int i, int sum){
    int n = candidates.size();
    if(sum > target) return ;
    if(sum == target){
        ans.push_back(v);
        return ;
    }
    if(i == n) return;
    
    v.push_back(candidates[i]);
    combSum(candidates, target, i + 1, sum + candidates[i]);
    v.pop_back();
    int j = i;
    while(i < n && candidates[i] == candidates[j]) i++;
    combSum(candidates, target, i, sum);
}


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        combSum(candidates, target, 0, 0);
        return ans;
    }
};