// https://practice.geeksforgeeks.org/problems/word-break1352/1
class Solution
{
    int dp[1101][1101];
public:
    bool solve(string s, int l, int r, vector<string> &dict){
        if(l > r) return 1;
        if(dp[l][r] != -1) return dp[l][r];
        string temp;
        for(int i = l; i <= r; i++) {
            temp += s[i];
            for(auto x: dict) {
                if(temp == x){
                    if (solve(s, i + 1, r, dict)) return dp[l][r] = true;
                }
            } 
        }
        return dp[l][r] = false;
    }

    int wordBreak(string A, vector<string> &B) {
        memset(dp, -1, sizeof(dp));
        return solve(A, 0, A.length() - 1, B);
    }
};