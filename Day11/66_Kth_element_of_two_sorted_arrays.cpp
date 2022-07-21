https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
class Solution{
    public:
    //  ITERATIVE(i still don't understand it completely)
    // int getK(int a[], int n, int b[], int m, int k){
    //     int l = max(0, k - m), r = min(n, k);
    //     // BS on array a[n] :O where we're doing it literally for the "index of partition"
    //     // | a0, a1, a2, ... or a0, .. a[n - 1],| so [0, n] is its range;
    //     int ind1 = 0, ind2 = 0;
    //     while(l <= r){
    //         int mid = (l + r) / 2;
    //         int x = mid, y = k - mid;
    //         int L1 = (x) ? a[x - 1]:INT_MIN;
    //         int L2 = (y) ? b[y - 1]:INT_MIN;
    //         int R1 = (x < n) ? a[x] : INT_MAX;
    //         int R2 = (y < m) ? b[y] :INT_MAX;
    //         if(L1 <= R2 && L2 <= R1) {
    //             ind1 = mid, ind2 = k - mid;
    //             break;
    //         }
    //         else if(L1 > R2) r = mid - 1;
    //         else l = mid + 1;
    //     }
        
    //     if(ind1 <= n){
    //         int x = (ind1) ? a[ind1 - 1]:INT_MIN;
    //         int y = (ind2) ? b[ind2 - 1]:INT_MIN;
    //         return max(x, y);
    //     }
        
    //     return b[ind2 - 1];
    // }
    
    
    // RECURSIVE BS
    int getK(int a[], int n, int b[], int m, int k){
        if(n > m) return getK(b, m, a, n, k);
        
        // a is always shorter array
        if(n == 0) {
            if(k == 0){
                cout<<n<<' '<<m<<' ';
                k = 1;
            }
            return b[k - 1];
        }
        if(k == 1) min(a[0], b[0]);
        
        // i + j == k should hold
        int i = min(n, k / 2);
        int j = k - i;
        
        // if(i >= n) return b[j];
        if(i == 0 || j == 0) {cout<<i<<' '<<j<<' '<<n<<' '<<m<<' ';i = 1;j = 1;}
        if(a[i - 1] < b[j - 1]) return getK(a + i, n - i, b, m, k - i);
        return getK(a, n, b + j, m - j, k - j);
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        return getK(arr1, n, arr2, m, k);
    }
};
