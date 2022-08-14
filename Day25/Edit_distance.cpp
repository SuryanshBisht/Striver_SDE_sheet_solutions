// https://leetcode.com/problems/edit-distance/
typedef long long int ll;

class Solution {
    ll dp[501][501];
public:
    ll foo(string a, string b, int n, int m){
        if(n == 0) return dp[n][m] = m;
        if(m == 0) return dp[n][m] = n;
        if(dp[n][m] != -1) return dp[n][m];
        ll ans = 501;
        if(a[n - 1] == b[m - 1])  
            ans = min(ans, foo(a, b, n - 1, m - 1));
        else{
            ans = min(ans, foo(a, b, n - 1, m) + 1);
            ans = min(ans, foo(a, b, n, m - 1) + 1);
            ans = min(ans, foo(a, b, n - 1, m - 1) + 1);
        }
        return dp[n][m] = ans;
    }
    
    int minDistance(string a, string b) {
        int n = a.length(), m = b.length();
        memset(dp, -1, sizeof(dp));
        int ans = foo(a, b, n, m);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m ; j++){
        //         cout<<dp[i][j]<<' ';
        //     }cout<<endl;
        // }
        
        return ans;
    }
};