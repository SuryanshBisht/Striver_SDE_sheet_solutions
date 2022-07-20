// https://leetcode.com/problems/maximum-product-subarray/submissions/
typedef long long int ll;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //like max subarray sum, here turning point at 0,
        //also take care of negatives, a trick to do is take local max, mins at every step and 
        //refresh global max, mins to get ultimate result kinda like
        //inloop{ localMin = min(globalMin*v[i], globalMax*v[i], v[i])}
        ll pro = 1, best = -10;
        for(auto x:nums){
            if(x){ 
                pro *= x;
                best = max(best, pro);
            }
            else pro = 1;
            best = max(best, ll(x));
        }
        
        pro = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i]){ 
                pro *= nums[i];
                best = max(best, pro);
            }
            else pro = 1;
            best = max(best, ll(nums[i]));
        }
        
        return best;
    }
};