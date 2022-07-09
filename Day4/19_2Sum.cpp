// https://leetcode.com/problems/two-sum/
//new 2 pointer solution nope all we can do is hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_map<int,int> m;
        for(int i = 0; i < v.size();i++){
           
            if(m[target - v[i]]){
                return vector<int> {m[target - v[i]] - 1, i};
            }
            
             m[v[i]] = i + 1;
        }
        
        return vector<int> {};
    }
};

//old solution by HASHING, its first q on leetcode duh
map<int,int> m;
        int n = nums.size();
        for(int i = 0;i < n; i++){
            m[nums[i]]++;
        }
        vector<int> res(2,0);
        for(int i = 0;i < n; i++){
            if(m[target - nums[i]] != 0){
                if(nums[i]*2 == target){
                    if(m[nums[i]] <= 1) continue;
                }
                res[0] = nums[i];
                res[1] = target - nums[i];
                return res;
            }
        }
        return res;