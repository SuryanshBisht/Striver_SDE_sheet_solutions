// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
class Solution{
    int dp[501][501];
public:
    bool isPali(string s, int i, int j){
        int l = i, r = j;
        while(l < r){
            if(s[l] != s[r]) return 0;
            l++;
            r--;
        }
        
        return 1;
    }

    int solve(string &s, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) return dp[i][j] = 0;
        if(isPali(s, i, j)) return dp[i][j] = 0;
        
        int ans = INT_MAX;
        for(int k = i ; k < j; k++){
            int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
            ans = min(ans, temp);
        }
        return  dp[i][j] = ans;
    }

    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, str.length() - 1);
    }
};