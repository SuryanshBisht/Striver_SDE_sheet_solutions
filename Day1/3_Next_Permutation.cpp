class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        int ind = n - 1;
        int temp  = v[ind];
        while(v[ind] >= temp){
            temp = v[ind];
            ind--;
            if(ind < 0) break;
        }
        
        if(ind == -1){
            for(int i = 0; i < n / 2; i++){
                swap(v[i], v[n - i - 1]);
            }
            return;
        }
        
        int l = ind + 1, r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(v[mid] > v[ind]){
                l = mid + 1;
            }
            else{
                r  = mid - 1;
            }
        }
        swap(v[ind], v[r]);
        
        l = ind + 1, r = n - 1;
        while(l < r){
            swap(v[l], v[r]);
            l++;
            r--;
        }
    }
};