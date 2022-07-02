class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum = 0, best = INT_MIN;
        for(auto x:v){
            sum += x;
            best = max(best, sum);
            sum = max(sum, 0);
        }
        return best;
    }
};

//name is maximum subarray in leetcode