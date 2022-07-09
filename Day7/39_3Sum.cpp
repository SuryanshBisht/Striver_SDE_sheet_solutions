// https://leetcode.com/problems/3sum/submissions/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        if(n < 3) return vector<vector<int>> ();
        
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i ++){
            if(i > 0 && v[i] == v[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while(l < r){
                if(v[i] + v[l] + v[r] > 0){
                    r--;
                }
                else if(v[i] + v[l] + v[r] < 0){
                    l++;
                }
                else{
                    ans.push_back({v[i], v[l], v[r]});
                    int x = v[l];
                    while(l < r && v[l] == x) l++;
                    x = v[r];
                    while(l < r && v[r] == x) r--;
                }
            }
        }
        
        return ans;
    }
};