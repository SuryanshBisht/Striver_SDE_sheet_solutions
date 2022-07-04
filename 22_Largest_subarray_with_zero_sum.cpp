// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> m;
        int sum = 0, res = 0;
        for(int  i = 0; i < n;i++){
            sum += A[i];
            if(m[sum] != 0){
                res = max(res, i + 1 - m[sum]);
            }
            else if(sum == 0){
                res = max(res, i + 1);
            }
            else m[sum] = i + 1;
        }

        return res;
    }
}
