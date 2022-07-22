// https://leetcode.com/problems/partition-equal-subset-sum/submissions/
class Solution {
public:
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for(auto x:v) sum += x;
        if(sum & 1) return false;
        bool dp[sum/2 + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = sum / 2; j >= 0; j--){
                if(j >= v[i]) dp[j] = dp[j] || dp[j - v[i]];
            }
        }
        
        return dp[sum / 2];
    }
};