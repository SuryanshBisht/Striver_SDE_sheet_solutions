// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
class Solution{

public:
    int foo(int arr[], int i, int j, vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) return 0;
        int mini = INT_MAX;
        for(int k = i; k < j;k++){
            mini = min(mini, 
             arr[i - 1] * arr[k] * arr[j] + foo(arr, i, k, dp) + foo(arr, k + 1, j, dp));
        }
        return dp[i][j] = mini;
    }

    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return foo(arr, 1, n - 1, dp);
    }
};