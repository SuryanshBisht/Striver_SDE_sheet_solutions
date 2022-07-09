// https://leetcode.com/problems/longest-consecutive-sequence/submissions/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m, done;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        
        for(auto v:nums){
            if(done[v]) continue;
            int x = v, left = 0, right = 0;
            done[v] = 1;
            while(m[x]){
                done[x] = 1;
                x++;
                right++;
            }
            
            x = v - 1;
            while(m[x]){
                done[x] = 1;
                x--;
                left++;
            }
            
            ans = max(left + right, ans);
        }
        
        return ans;
    }
};