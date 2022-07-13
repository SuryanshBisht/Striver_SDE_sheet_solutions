// https://leetcode.com/problems/subsets-ii/submissions/
class Solution {
    vector<vector<int>> ans;
    vector<int> v;
public:
    void subsets(vector<int> &nums, int ind){
        if(ind == nums.size()){
            ans.push_back(v);
            return;
        }
           
        int i = ind;
        while(ind < nums.size() && nums[i] == nums[ind]) ind++;
        subsets(nums, ind);
        v.push_back(nums[i]);
        subsets(nums, i + 1);
        v.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(), nums.end());
        subsets(nums, 0);
        return ans;
    }
};