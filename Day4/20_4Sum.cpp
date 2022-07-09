// https://leetcode.com/problems/4sum/
// Nice Discussion below
// https://leetcode.com/problems/4sum/discuss/8549/My-16ms-c%2B%2B-code
// learnings about trying to prevent repetitions


// OPP solution without vector of set, we're basically allowing the first instances of every 
// element to take part for first two, for left and right we only care about that
// after an answer is found, take left and right to extremes to avoid those answers
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // set<vector<int> > v;
        vector<vector<int>> ans;
        int n = nums.size();
        if(n <= 3){
            return vector<vector<int>> ();
        }
        
        
        sort(nums.begin(), nums.end());
       
        
        for(int a = 0; a < n - 3; a++){
            if(a > 0 && nums[a] == nums[a - 1]) continue;// magic's here
            for(int b = a + 1; b < n - 2; b++){
                if(b > a + 1 && nums[b] == nums[b - 1]) continue; // and here
                int c = b + 1, d = n - 1;
                while(c < d){
                    long long int a1 = nums[a], a2 = nums[b], a4 = nums[c], a3 = nums[d], f = target;
                    if(a1 + a2 + a3 + a4 < f){  
                        c++;
                    }
                    else if(a1 + a2 + a3 + a4 > f){
                        d--;
                    }
                    else{
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        // and here as well
                        int  x = nums[c];
                        while(x == nums[c] && c < d){
                            c++;
                            if(c == d) break;
                        }
                        
                        x = nums[d];
                        while(x == nums[d] && c < d){
                            d--;
                            if(d == c) break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};

//my 1st solve
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int> > v;
        // vector<vector<int>> ans;
        int n = nums.size();
        if(n <= 3){
            return vector<vector<int>> (v.begin(), v.end());
        }
        sort(nums.begin(), nums.end());
        // int ind = 0;
//         for(int i = 1;  i < n - 4; i++){
//             if(v[i + 4] == v[i]){
//                 ind = i + 4;
//             }
//             else{
//                 v[ind] = v[i];
//                 ind++;
//             }
//         }
        
        for(int a = 0; a < n - 3; a++){
            for(int b = a + 1; b < n - 2; b++){
                int c = b + 1, d = n - 1;
                while(c < d){
                    long long int a1 = nums[a], a2 = nums[b], a4 = nums[c], a3 = nums[d], f = target;
                    if(a1 + a2 + a3 + a4 < f){
                        int x = nums[c];
                        while(x == nums[c]){
                            c++;
                            if(c == d) break;
                        }
                    }
                    else{
                        if(a1 + a2 + a3 + a4 == f){ //or(nums[a] + nums[b] == target - nums[c] - nums[d]) see ranges!
                            v.insert({nums[a], nums[b], nums[c], nums[d]});
                        }
                        int x = nums[d];
                        while(x == nums[d]){
                            d--;
                            if(d == c) break;
                        }
                    }
                }
            }
        }
        
        
        
        // for(auto x = v.begin(); x != v.end() ; x++){
        //     ans.push_back(*x);
        // }
        return vector<vector<int>> (v.begin(), v.end());
    }
};