// https://leetcode.com/problems/coin-change/submissions/
class Solution {
    // int dp[10001];
    vector<int> dp; // vector works fine but not array, STRANGE

public:
    int solve(vector<int> &coins, int amount){
        if(amount < 0) return -1;
        if(amount == 0) return  dp[amount] = 0;
        if(dp[amount] != -2) return dp[amount];
        int mini = INT_MAX, validSum = 0;
        for(auto x:coins){
            int temp = solve(coins, amount - x);
                // cout<<temp<<' ';
            if(temp == -1) continue;
            mini = min(temp, mini);
            validSum = true;    
        }
        // cout<<endl;
        if(!validSum) return dp[amount] = -1;
        return dp[amount] = mini + 1;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<int> (10001, -2);
        // memset(dp, -2, sizeof(dp));
        // Note: We can use memset() to set all values of string to any char and all values
        // as 0 or -1 for integral data types. 
        // It will not work if we use it to set as other values. The reason is simple, memset works byte by byte.  
        return solve(coins, amount);
    }
};