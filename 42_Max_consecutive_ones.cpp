// https://leetcode.com/problems/max-consecutive-ones/submissions/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, best = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                count++;
            }
            else count = 0;
            best = max(best, count);
        }
        
        return best;
    }
};