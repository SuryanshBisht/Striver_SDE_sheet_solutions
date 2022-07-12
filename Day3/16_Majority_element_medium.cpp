// https://leetcode.com/problems/majority-element-ii/
// MY GENIOUS CODE
class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int max1 = 0, f1 = 0, max2 = 0, f2 = 0;
        for(auto x:v){
            if(f1 == 0 && f2 == 0) {
                max1 = x;f1++;
            }
            else if(f2 == 0 && x != max1) {max2 = x;f2++;}
            else if(f1 == 0 && x != max2) {max1 = x;f1++;}
            else if(x == max1) f1++;
            else if(x == max2) f2++;
            else {
                f1--;f2--;
            }
        }
        // cout<<max1<<' '<<max2;
        f1 = 0, f2 = 0;
        for(auto x:v){
            if(x == max1) f1++;
            else if(x == max2) f2++;
        }
        
        vector<int> ans;
        if(f1 > v.size() / 3) ans.push_back(max1);
        if(f2 > v.size() / 3) ans.push_back(max2);
        return ans;
    }
};