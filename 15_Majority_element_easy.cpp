// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& v) {
        int count = 1, ind = 0, n = v.size();
        for(int i = 1; i < n; i ++){
            if(v[i] == v[ind]){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                count = 1;
                ind = i;
            }
        }
        
        return v[ind];
    }
};