// https://leetcode.com/problems/ones-and-zeroes/submissions/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        vector<pair<int,int>> count(N, {0,0});
        for(int i = 0; i < N; i++){
            for(auto c:strs[i]) {
                if(c == '1') count[i].first++;
                else count[i].second++;
            }
        }
        
        for(int k = 0; k < N; k++){
            int ones = count[k].first, zero = count[k].second;
            for(int i = m; i >= 0; i--){
                for(int j = n; j >= 0; j--){
                    if(i >= zero && j >= ones){
                        dp[i][j] = max(dp[i][j], dp[i - zero][j - ones] + 1);
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};