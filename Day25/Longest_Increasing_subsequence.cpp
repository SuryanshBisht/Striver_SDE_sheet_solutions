// https://leetcode.com/problems/longest-increasing-subsequence/submissions/
class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp; //dp[i] = minimum "tail" of subseqs of length i + 1
        //O(nlogn) sol
        //new kind of nlogn, here we iterate and operate on an array in logn, maintaining it sorted
        for(auto x: v){
            int l = 0, r = dp.size() - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                (dp[mid] < x) ? (l = mid + 1) : (r = mid - 1);
            }
            if(l == dp.size()) dp.push_back(x); 
            else dp[l] = min(x, dp[l]);  
        }
        // for(auto x:dp) cout<<x<<' ';cout<<endl;
        return dp.size();
        
        //first sol
        // for(int i = 0; i < n ;i++){
        //     for(int j = i - 1; j >= 0; j--){
        //         if(v[j] < v[i])  dp[i] = max(dp[i], dp[j] + 1);
        //     }
        //     res = max(res, dp[i]);
        // }
        
        // return res;
    }
};