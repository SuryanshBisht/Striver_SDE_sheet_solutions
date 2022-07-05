// https://leetcode.com/problems/majority-element-ii/submissions/
//my dp solution
vector<vector<int>> dp(101, vector<int>(101));

int paths(int i, int j, int m, int n){
    if(dp[i][j]) return dp[i][j];
    if(i == m || j == n) return dp[i][j] = 1;
    return dp[i][j] = paths(i + 1, j, m, n) + paths(i, j + 1, m, n);
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        for(int i = 0; i <= 100; i++){
            for(int j =0; j <= 100; j++){
                dp[i][j] = 0;
            }
        }
        return paths(1, 1, m, n);
    }
};

// but better solution is using combinartrics (n + m - 1)C (m - 1) for n x m grid
// and to find it here's the method
long res = 1;

for(int i = m+1, j = 1; i <= m+n; i++, j++){// Instead of taking factorial, keep on multiply & divide
    res *= i;
    res /= j;
}
    
return (int)res;