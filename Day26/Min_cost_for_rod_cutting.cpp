// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
class Solution {
    int dp[101][101];
public:
    int solve(vector<int> &cuts, int i, int j, int l, int r){
        if(i > j) return 0;
        if(i == j) return r - l ;
        //in this particular question, the lengths is measured as r - l instead of r - l + 1
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k <= j; k++){
            int temp = r - l + solve(cuts, i, k - 1, l, cuts[k]) + solve(cuts, k + 1, j, cuts[k], r);
            ans = min(temp, ans);
        }
        // cout<< i<<' '<<j<<' '<<ans<<' ';
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size() - 1, 0, n);
    }
};