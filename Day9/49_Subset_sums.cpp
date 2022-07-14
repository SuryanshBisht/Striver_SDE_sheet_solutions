// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
class Solution {
    vector<int> ans;
public:
    void sums(vector<int> &v, int sum, int ind){
        if(ind == v.size()){
            ans.push_back(sum);
            return;
        }
        sums(v, sum, ind + 1);
        sums(v, sum + v[ind], ind + 1);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        ans.clear();
        sums(arr, 0, 0);
        return ans;
    }
};