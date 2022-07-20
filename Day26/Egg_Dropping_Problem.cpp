// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int foo(vector<vector<int>> &dp, int n, int k){
        if(dp[n][k] != -1) return dp[n][k] ;
        if(k <= 1 || n == 1) return dp[n][k] = k;
        int mini = INT_MAX;
        for(int i = 1; i <= k; i++){
            int temp = 1 + max(foo(dp, n, k - i), foo(dp, n - 1, i - 1));
            mini = min(temp,mini);
        }
        return dp[n][k] = mini;
    }
    
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
        return foo(dp, n, k);
    }
};
