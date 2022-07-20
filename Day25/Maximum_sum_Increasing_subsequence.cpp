// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// for O(nlogn) what we had in LIS is that we knew that the 'tails' will always be sorted, 
// in this case we can do theoretically, but implementing is just senseless
// we can maintain a dp<pii> with {sum, tailend}, then BS dp find point where
// x is just greater than tailend , update as {sum + x, x}, let it 
// do its sorting thing
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp = vector<int> (arr, arr + n);
	    int res = INT_MIN;
	    for(int i = 0; i < n ; i++){
	        for(int j = i - 1; j >= 0; j--){
	            if(arr[j] < arr[i]) {
	                dp[i] = max(dp[i], arr[i] + dp[j]);
	            }
	        }
	        res = max(res, dp[i]);
	    }
	    return res;
	}  
};