// https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n / 2 - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(v[mid * 2] == v[2 * mid + 1]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return v[l *2];
    }
};