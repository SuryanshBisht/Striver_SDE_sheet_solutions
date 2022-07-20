// https://leetcode.com/problems/longest-common-subsequence/submissions/
class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.length(), m = b.length();
        vector<int> dp(n + 1);
        
        for(int i = 1 ;i <= m ; i ++){
            vector<int> curr(n + 1);
            for(int j = 1; j <= n; j++){
                if(a[j - 1] == b[i - 1]){
                    curr[j] = dp[j - 1] + 1;
                }
                else{
                    curr[j] = max(dp[j], curr[j - 1]);
                }
            }
            dp = curr;
        }
                
        return dp[n];
    }
};