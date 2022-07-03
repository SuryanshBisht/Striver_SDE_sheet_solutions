//https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include <bits/stdc++.h> 
using namespace std;

long long invCount(long long arr[], long long l, long long r){
    // NEVER DO THAT EVER AGAIN, I MEAN OFC L <= R ALWAYS
    // if(l <= r){
    //     return 0;
    // }
    
    if(l == r) return 0;
    long long mid = (l + r) / 2;
    long long ans = 0;
    ans += invCount(arr, l, mid);
    ans += invCount(arr, mid + 1, r);
    vector<long long> temp(r - l + 1);
 
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
            ans += mid - i + 1; 
            // if arr[i] > arr[j], so will be the elements ahead of arr[l]
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
    arr += l;
    for(int i = 0; i < k ; i++){
        arr[i + l] = temp[i];
    }
    return ans;
}



long long getInversions(long long *arr, int n){
//     for(int i = 0; i < n; i++ ) cout<<arr[i]<< ' ';
    long long a[n];
    for(int i = 0; i < n; i++){
        a[i] = *(arr + i);
    }
    return invCount(a, 0, n - 1);
}

int main(){
    int n; cin>>n;
    long long int arr[n];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }

    cout<<getInversions(arr, n)<<"\n";


    for(int i =0 ; i < n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<"\n";

    return 0;
}