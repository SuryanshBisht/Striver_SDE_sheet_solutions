// https://leetcode.com/problems/minimum-path-sum/
class Solution {
    int dp[201][201];
public:
    // this q can even be solved in O(1) memory complexity, think about it!
    int solve(vector<vector<int>> &grid, int i, int j, int n, int m){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n - 1&& j == m - 1) return dp[i][j] = grid[i][j];
        if(i < n - 1 && j < m - 1){
            return dp[i][j] = grid[i][j] + min(solve(grid, i + 1, j, n, m), solve(grid, i, j + 1, n, m));
        }
        if(i < n - 1) return dp[i][j] = grid[i][j] + solve(grid, i + 1, j, n, m);
        if(j < m - 1) return dp[i][j] = grid[i][j] + solve(grid, i, j + 1, n, m);
        return -1;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return solve(grid, 0, 0, m, n);
    }
};