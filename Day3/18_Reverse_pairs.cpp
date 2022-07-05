// https://leetcode.com/problems/reverse-pairs/
int revPairs(vector<int> &arr, int l, int r){
    // if(l <= r){ DAAAAMN, NEVER GONANA DO THAT AGAIN 
    //     return 0;
    // }
    
    if(l == r) return 0;
    
    // if(r - l == 1){
    //     if(arr[l] > arr[r]){
    //         swap(arr[l], arr[r]);
    //         if(arr[l] > 2 * arr[r]) {
    //             return 1;
    //         }
    //     }
    //     return 0;
    // }
   
    int mid = (l + r) / 2,  ans = 0;
    ans += revPairs(arr, l, mid);
    ans += revPairs(arr, mid + 1, r);
    vector<int> temp(r - l + 1, 0);
 
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        long long x = arr[i], y = arr[j];
        if(x > 2 * y){
            ans += mid - i + 1;
            j++;
        }
        else{
            i++;
        }
    }
    
    i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
            // if arr[i] > arr[j], so will be the elements ahead of arr[l]
            // man just do all stuff before incrementin j, k
        }
    }
    
    
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while(j <= r){
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    for(int i = 0; i < k ; i++){
        arr[i + l] = temp[i];
        // cout<<temp[i]<<' ';
    
    }
    // cout<<'\n';
    
    return ans;
}


class Solution {
public:
    int reversePairs(vector<int>& arr) {
        int ans = revPairs(arr, 0, arr.size() - 1);
        // for(auto x:arr) cout<<x<<' ';cout<<"\n";
        return ans;
    }
};